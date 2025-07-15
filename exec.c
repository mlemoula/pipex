/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:05 by mlemoula          #+#    #+#             */
/*   Updated: 2025/07/15 11:30:25 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_single_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*complete_path;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		complete_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(complete_path, X_OK) == 0)
			return (complete_path);
		free(complete_path);
		i++;
	}
	return (NULL);
}

static char	*ft_get_cmd_path(t_pipex *pipex, char *cmd)
{
	char	**paths;
	char	*env_path;
	char	*single_path;
	int		i;

	i = 0;
	env_path = NULL;
	if (!cmd || !access(cmd, X_OK))
		return (ft_strdup(cmd));
	while (pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
		{
			env_path = pipex->envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	single_path = ft_get_single_path(paths, cmd);
	ft_clean_charptrptr(paths);
	return (single_path);
}

static void	ft_execute(t_pipex *pipex, char **cmd)
{
	char	*cmd_path;

	cmd_path = ft_get_cmd_path(pipex, cmd[0]);
	if (!cmd_path)
	{
		perror(cmd[0]);
		ft_exit(pipex, 1);
	}
	execve(cmd_path, cmd, pipex->envp);
	perror("execve");
	free(cmd_path);
	exit(EXIT_FAILURE);
}

static pid_t	ft_forking(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		ft_exit(pipex, 1);
	}
	return (pid);
}

static void	ft_execute_child(t_pipex *pipex, int in_fd, int out_fd, char **cmd)
{
	if (in_fd == -1)
	{
		close(pipex->pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	ft_execute(pipex, cmd);
}

void	ft_process(t_pipex *pipex)
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		status_1;
	int		status_2;

	pid_1 = ft_forking(pipex);
	if (pid_1 == 0)
		ft_execute_child(pipex, pipex->fd_infile,
			pipex->pipefd[1], pipex->parsed_cmd1);
	pid_2 = ft_forking(pipex);
	if (pid_2 == 0)
		ft_execute_child(pipex, pipex->pipefd[0],
			pipex->fd_outfile, pipex->parsed_cmd2);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(pid_1, &status_1, 0);
	waitpid(pid_2, &status_2, 0);
	if (WIFEXITED(status_1) && WEXITSTATUS(status_1) != 0)
		ft_exit(pipex, EXIT_SUCCESS);
	if (WIFEXITED(status_2) && WEXITSTATUS(status_2) != 0)
		ft_exit(pipex, EXIT_FAILURE);
}

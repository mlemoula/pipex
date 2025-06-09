/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:05 by mlemoula          #+#    #+#             */
/*   Updated: 2025/06/09 20:40:28 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *ft_get_single_path(char **paths, char *cmd)
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
		{
			ft_clean_charptrptr(paths);
			return (complete_path);
		}
		free(complete_path);
		i++;
	}
	ft_clean_charptrptr(paths);
	return (NULL);
}

static char	*ft_get_cmd_path(t_pipex *pipex, char *cmd)
{
	char	**paths;
	char	*env_path;
	char 	*single_path;
	int		i;

	i = 0;
	env_path = NULL;
	if (!cmd || !access(cmd, X_OK))
		return (ft_strdup(cmd));
	while(pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
		{
			env_path = pipex->envp[i] + 5;
			break;
		}
		i++;
	}
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	single_path = ft_get_single_path(paths, cmd);
	return (single_path);
}


static void	ft_execute(t_pipex *pipex, char **cmd)
{
	char	*cmd_path;

	cmd_path = ft_get_cmd_path(pipex, cmd[0]);
	if (!cmd_path)
	{
		perror(cmd[0]);
		ft_clean(pipex, 1);
	}
	execve(cmd_path, cmd, pipex->envp);
	perror("execve");
	free(cmd_path);
	ft_clean(pipex, 1);
}

void	ft_forking(t_pipex *pipex)
{
	pid_t	pid_1;
	pid_t	pid_2;

	pid_1 = fork();
	if (pid_1 < 0)
	{
		perror("fork");
		ft_clean(pipex, 1);
	}
	if (pid_1 == 0)//child process fork 1
	{
		dup2(pipex->fd_infile, STDIN_FILENO);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		ft_execute(pipex, pipex->parsed_cmd1);
	}
	pid_2 = fork();
	if (pid_2 < 0)
	{
		perror("fork");
		ft_clean(pipex, 1);
	}
	if (pid_2 == 0)	//child process fork 2
	{
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->fd_outfile, STDOUT_FILENO);
		close(pipex->pipefd[1]);
		close(pipex->pipefd[0]);
		ft_execute(pipex, pipex->parsed_cmd2);
	}
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(pid_1, 0, 0);
	waitpid(pid_2, 0, 0);
}

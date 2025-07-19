/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:51:13 by mlemoula          #+#    #+#             */
/*   Updated: 2025/07/20 01:12:01 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_charptrptr(char **parsed_cmd)
{
	int	i;

	if (!parsed_cmd)
		return ;
	i = 0;
	while (parsed_cmd[i])
	{
		free(parsed_cmd[i]);
		i++;
	}
	free(parsed_cmd);
}

void	ft_clean(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->parsed_cmd1)
		ft_clean_charptrptr(pipex->parsed_cmd1);
	if (pipex->parsed_cmd2)
		ft_clean_charptrptr(pipex->parsed_cmd2);
	if (pipex->fd_infile >= 0)
		close(pipex->fd_infile);
	if (pipex->fd_outfile >= 0)
		close(pipex->fd_outfile);
	if (pipex->pipefd[0] >= 0)
		close (pipex->pipefd[0]);
	if (pipex->pipefd[1] >= 0)
		close (pipex->pipefd[1]);
	if (pipex->error_msgs)
		free(pipex->error_msgs);
}

void	ft_exit(t_pipex *pipex, int exit_code)
{
	if (pipex->error_msgs)
	{
		ft_putstr_fd(pipex->error_msgs, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	ft_clean(pipex);
	exit(exit_code);
}

void	ft_set_error(t_pipex *pipex, const char *context, const char *msg)
{
	char	*tmp;

	if (!pipex || !context || !msg)
		return ;
	tmp = ft_strjoin(context, ": ");
	if (!tmp)
		return ;
	pipex->error_msgs = ft_strjoin(tmp, msg);
	free(tmp);
}

void	ft_set_errno_error(t_pipex *pipex, const char *context)
{
	ft_set_error(pipex, context, strerror(errno));
}

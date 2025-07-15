/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:51:13 by mlemoula          #+#    #+#             */
/*   Updated: 2025/07/15 14:42:18 by mlemoula         ###   ########.fr       */
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
}

void	ft_exit(t_pipex *pipex, int exit_code)
{
	ft_clean(pipex);
	exit(exit_code);
}

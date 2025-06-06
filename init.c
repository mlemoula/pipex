/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:23:52 by mlemoula          #+#    #+#             */
/*   Updated: 2025/06/06 15:38:07 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex *pipex, char **argv)
{
	pipex->infile = argv[1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->outfile = argv[4];
	pipex->parsed_cmd1 = NULL;
	pipex->parsed_cmd2 = NULL;
}

void	ft_init_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipefd) != 0)
	{
		perror("pipe");
		ft_clean(pipex, 1);
	}
}

void	ft_init_fork(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
	{
		perror("fork");
		ft_clean(pipex, 1);
	}
}

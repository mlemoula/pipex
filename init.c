/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:23:52 by mlemoula          #+#    #+#             */
/*   Updated: 2025/06/10 18:50:45 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	pipex->infile = argv[1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->outfile = argv[4];
	pipex->fd_infile = -1;
	pipex->fd_outfile = -1;
	pipex->parsed_cmd1 = NULL;
	pipex->parsed_cmd2 = NULL;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
	pipex->envp = envp;
}

void	ft_init_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipefd) != 0)
	{
		perror("pipe");
		ft_exit(pipex, EXIT_FAILURE);
	}
}

void	ft_parse_cmds(t_pipex *pipex)
{
	pipex->parsed_cmd1 = ft_split(pipex->cmd1, ' ');
	pipex->parsed_cmd2 = ft_split(pipex->cmd2, ' ');
	if (!pipex->parsed_cmd1 || !pipex->parsed_cmd2)
		ft_exit(pipex, EXIT_FAILURE);
}

void	ft_check_files(t_pipex *pipex)
{
	if (access(pipex->infile, R_OK) != 0)
		perror(pipex->infile);
		// ft_exit(pipex, EXIT_SUCCESS);
	else
	{
		pipex->fd_infile = open(pipex->infile, O_RDONLY);
		if (pipex->fd_infile < 0)
		{
			perror(pipex->infile);
			// ft_exit(pipex, EXIT_FAILURE);
		}
	}
	if (access(pipex->outfile, F_OK) == 0 && access(pipex->outfile, W_OK) != 0)
	{
		perror(pipex->outfile);
		ft_exit(pipex, EXIT_FAILURE);
	}
	pipex->fd_outfile = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC);
	if (pipex->fd_outfile < 0)
	{
		perror(pipex->outfile);
		ft_exit(pipex, EXIT_FAILURE);
	}
}

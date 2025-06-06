/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:59:19 by mlemoula          #+#    #+#             */
/*   Updated: 2025/06/06 15:38:11 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_files(t_pipex *pipex)
{
	// if (!pipex.infile || !pipex.outfile)
	// 	return (0);
	if (access(pipex->infile, R_OK) != 0)
	{
		perror(pipex->infile);
		ft_clean(pipex, 1);
	}
	pipex->fd_infile = open(pipex->infile, O_RDONLY);
	if (pipex->fd_infile < 0)
	{
		perror(pipex->infile);
		ft_clean(pipex, 1);
	}
	if (access(pipex->outfile, F_OK) == 0 && access(pipex->outfile, W_OK) != 0)
	{
		perror(pipex->outfile);
		ft_clean(pipex, 1);
	}
	pipex->fd_outfile = open(pipex->outfile, O_CREAT | O_WRONLY);
	if (pipex->fd_outfile < 0)
	{
		perror(pipex->outfile);
		ft_clean(pipex, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:59:19 by mlemoula          #+#    #+#             */
/*   Updated: 2025/05/31 18:46:10 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_files(t_pipex *pipex)
{
	// if (!pipex.infile || !pipex.outfile)
	// 	return (0);
	if (access(pipex->infile, R_OK) != 0)
		return (perror(pipex->infile), 0);
	pipex->fd_infile = open(pipex->infile, O_RDONLY);
	if (pipex->fd_infile < 0)
		return (perror (pipex->infile), 0);
	if (access(pipex->outfile, F_OK) == 0 && access(pipex->outfile, W_OK) != 0)
		return (perror(pipex->outfile), 0);
	pipex->fd_outfile = open(pipex->outfile, O_CREAT | O_WRONLY);
	if (pipex->fd_outfile < 0)
		return (perror (pipex->outfile), 0);
	return (1);
}
// stocker les fd > pipex->fd
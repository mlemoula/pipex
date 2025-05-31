/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:59:19 by mlemoula          #+#    #+#             */
/*   Updated: 2025/05/14 14:25:11 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_args(t_pipex pipex, int argc, char **argv)
{
	if (argc != 5)
		return (0);
	if (!pipex.infile || !pipex.outfile)
		return (0);
	if (access(pipex.infile, R_OK) != 0)
		return (0);
	// if (access(pipex.outfile, W_OK) != 0)
	// 	return (0);
	if (!(open(pipex.outfile, O_CREAT | O_WRONLY) > 0))
		return (0);
}

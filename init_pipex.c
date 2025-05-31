/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:23:52 by mlemoula          #+#    #+#             */
/*   Updated: 2025/05/10 20:46:21 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex *pipex, int argc, char **argv)
{
	if (argc == 5)
	{
		pipex->infile = argv[1];
		pipex->cmd1 = argv[2];
		pipex->cmd2 = argv[3];
		pipex->outfile = argv[4];
	}
	else
	{
		pipex->infile = NULL;
		pipex->cmd1 = NULL;
		pipex->cmd2 = NULL;
		pipex->outfile = NULL;
	}
	pipex->parsed_cmd1 = NULL;
	pipex->parsed_cmd2 = NULL;
}

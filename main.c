/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:15:49 by mlemoula          #+#    #+#             */
/*   Updated: 2025/05/31 18:38:28 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	pipex;

	// ft_printf("argc: %d\n", argc);
	if (argc != 5)
		return (-1);
	ft_init_pipex(&pipex, argv);
	if (!ft_check_files(&pipex))
		ft_clean(&pipex, 1);
	// ft_parse_cmds(&pipex);
	// while (cmds)
	// 	ft_exec()
	// ft_cleanup()
	// ft_printf("Hello la dedans");
	// ft_printf("infile: %s\noutfile: %s\ncmd1: %s\ncmd2: %s\n",
		// pipex.infile, pipex.outfile, pipex.cmd1, pipex.cmd2);
	ft_clean(&pipex, 0);
	return (0);
}

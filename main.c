/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:15:49 by mlemoula          #+#    #+#             */
/*   Updated: 2025/06/09 20:27:45 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (-1);
	ft_init_pipex(&pipex, argv, envp);
	ft_check_files(&pipex);
	ft_parse_cmds(&pipex);
	ft_init_pipe(&pipex);
	ft_forking(&pipex);
	ft_clean(&pipex, 0);
	return (0);
}

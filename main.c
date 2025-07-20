/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:15:49 by mlemoula          #+#    #+#             */
/*   Updated: 2025/07/20 16:02:02 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	ft_init_pipex(&pipex, argv, envp);
	ft_check_files(&pipex);
	ft_parse_cmds(&pipex);
	if (pipe(pipex.pipefd) == -1)
	{
		ft_set_error(&pipex, "pipe", strerror(errno));
		ft_exit(&pipex, 1);
	}
	ft_process(&pipex);
	ft_clean(&pipex);
	return (0);
}

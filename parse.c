/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:48:02 by mlemoula          #+#    #+#             */
/*   Updated: 2025/06/09 19:43:05 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parse_cmds(t_pipex *pipex)
{
	pipex->parsed_cmd1 = ft_split(pipex->cmd1, ' ');
	pipex->parsed_cmd2 = ft_split(pipex->cmd2, ' ');
	if (!pipex->parsed_cmd1 || !pipex->parsed_cmd2)
		ft_clean(pipex, 1);
}

// ft_parse_input(t_pipex *pipex);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:48:02 by mlemoula          #+#    #+#             */
/*   Updated: 2025/05/31 17:54:48 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parse_cmds(t_pipex *pipex)
{
	if (ft_strchr(pipex->cmd1, ' '))
	{
		pipex->parsed_cmd1 = ft_split(pipex->cmd1, ' ');
		if (!pipex->parsed_cmd1)
			return (-1);
	}
	if (ft_strchr(pipex->cmd2, ' '))
	{
		pipex->parsed_cmd2 = ft_split(pipex->cmd2, ' ');
		if (!pipex->parsed_cmd2)
		{
			while (pipex->parsed_cmd1)
			{
				
			}
			return (-1);
		}
	return (1);
}

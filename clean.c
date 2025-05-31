/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:51:13 by mlemoula          #+#    #+#             */
/*   Updated: 2025/05/10 18:28:48 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_clean_parsed_cmd(char **parsed_cmd)
{
	int	i;

	if (!parsed_cmd || !*parsed_cmd)
		return ;
	i = 0;
	while (parsed_cmd[i])
	{
		free(parsed_cmd[i]);
		i++;
	}
	free(parsed_cmd);
}

void	ft_clean(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->parsed_cmd1)
		ft_clean_parsed_cmd(pipex->parsed_cmd1);
	if (pipex->parsed_cmd2)
		ft_clean_parsed_cmd(pipex->parsed_cmd2);
}

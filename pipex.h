/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:21 by mlemoula          #+#    #+#             */
/*   Updated: 2025/05/10 21:26:16 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./libft/ft_printf.h"
# include <fcntl.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	**parsed_cmd1;
	char	**parsed_cmd2;
}	t_pipex;

int		ft_check_args(t_pipex pipex, int argc, char **argv);
void	ft_init_pipex(t_pipex *pipex, int argc, char **argv);
void	ft_parse_cmds(t_pipex *pipex);
void	ft_clean(t_pipex *pipex);

#endif
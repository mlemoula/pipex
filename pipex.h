/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:21 by mlemoula          #+#    #+#             */
/*   Updated: 2025/07/20 15:41:06 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./libft/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**envp;
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	**parsed_cmd1;
	char	**parsed_cmd2;
	int		fd_infile;
	int		fd_outfile;
	int		pipefd[2];
	char	*error_msgs;
}	t_pipex;

void	ft_check_files(t_pipex *pipex);
void	ft_init_pipex(t_pipex *pipex, char **argv, char **envp);
int		ft_is_empty(char *s);
void	ft_parse_cmds(t_pipex *pipex);
void	ft_clean_charptrptr(char **parsed_cmd);
void	ft_exit(t_pipex *pipex, int exit_code);
void	ft_clean(t_pipex *pipex);
pid_t	ft_forking(t_pipex *pipex);
void	ft_process(t_pipex *pipex);
void	ft_set_error(t_pipex *pipex, const char *context, const char *msg);

#endif
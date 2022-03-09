/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:22 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 16:23:48 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_pipex
{
	int		arc;
	char	**arv;
	char	**env;
}			t_pipex;

void	execute_command(char *cmd, char **env);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	error_exit(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *symb);
int		open_out_file(int argc, char **argv);
void	child_proc(t_pipex *pip, int *fds, int i);
void	parent_proc(t_pipex *pip, int *fds, int i, int pid);
void	pipex(t_pipex *pip, int i);
#endif

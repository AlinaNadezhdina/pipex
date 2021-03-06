/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:22 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 16:03:35 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	execute_command(char *cmd, char **env);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	error_exit(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *symb);
#endif

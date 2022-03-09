/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:21:50 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 15:52:18 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int symb);
char	*ft_strjoin1(char const *s1, char const *s2);
size_t	ft_strlen1(const char *symb);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif

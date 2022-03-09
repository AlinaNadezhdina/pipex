/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:21:50 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 15:52:02 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	10
#endif

char	*return_str(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ret = ft_substr(str, 0, i);
	return (ret);
}

char	*return_rem(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	ret = ft_substr(str, i, ft_strlen1(str));
	free(str);
	return (ret);
}

char	*add_buf(char *remainder, char *buf, int fd)
{
	int	n_bytes;

	n_bytes = 1;
	while (n_bytes != 0 && ft_strchr((const char *)remainder, '\n') == NULL)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[n_bytes] = '\0';
		if (!remainder)
			remainder = ft_substr(buf, 0, n_bytes);
		else
			remainder = ft_strjoin1(remainder, buf);
	}
	free(buf);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*remainder;
	char		*ret_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	remainder = add_buf(remainder, buf, fd);
	if (!remainder || remainder[0] == '\0')
	{
		free(remainder);
		remainder = 0;
		return (NULL);
	}
	ret_str = return_str(remainder);
	if (!ret_str || ret_str[0] == '\0')
	{
		free(ret_str);
		return (NULL);
	}
	remainder = return_rem(remainder);
	return (ret_str);
}

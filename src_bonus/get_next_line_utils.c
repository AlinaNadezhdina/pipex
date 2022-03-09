/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:21:50 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 15:52:58 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *symb)
{
	unsigned long	length;

	length = 0;
	while (*symb)
	{
		length++;
		symb++;
	}
	return (length);
}

char	*ft_strchr(const char *str, int symb)
{
	int	i;

	if (!str)
		return ((void *)0);
	i = 0;
	while (str[i] != (unsigned char)symb)
	{
		if (str[i] == '\0')
			return ((void *)0);
		i++;
	}
	return ((char *)&str[i]);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return ((void *)0);
	i = 0;
	result = malloc(sizeof(char) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (result == (void *)0)
		return ((void *)0);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	free((void *)s1);
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen1(str);
	i = 0;
	dst = malloc(sizeof(*str) * (str_len + 1));
	if (dst == ((void *)0))
		return ((void *)0);
	while (i < str_len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return ((void *)0);
	s_len = ft_strlen1(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	dest = malloc(sizeof(*s) * (len + 1));
	if (dest == (void *)0)
		return ((void *)0);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:37:03 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 23:34:43 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	if (num == 0)
		return (0);
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2 && num > 1)
	{
		str1++;
		str2++;
		num--;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

size_t	ft_strlen(const char *symb)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return ((void *)0);
	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == (void *)0)
		return ((void *)0);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

void	error_exit(const char *str)
{
	perror(str);
	exit(1);
}

int	open_out_file(int argc, char **argv)
{
	int	file;

	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		file = open(argv[argc - 1], O_WRONLY + O_APPEND + O_CREAT, 0644);
	else
		file = open(argv[argc - 1], O_WRONLY + O_TRUNC + O_CREAT, 0644);
	return (file);
}

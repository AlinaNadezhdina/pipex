/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:35:00 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 23:26:19 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	find_str_num(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*check_path(char **path_arr, char *cmd, char *env)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '~')
		return (cmd);
	while (path_arr[i])
	{
		tmp = ft_strjoin(path_arr[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == -1)
		{
			i++;
			free(path);
		}
		else
			return (path);
	}
	return (NULL);
}

void	make_arr_free(char **arr1, char **arr2)
{
	free_array(arr1);
	free_array(arr2);
}

void	execute_command(char *argv_cmd, char **env)
{
	int		i;
	char	*path;
	char	**path_arr;
	char	**cmd_arr;

	i = find_str_num(env);
	if (i == -1)
		error_exit("Path not found");
	cmd_arr = ft_split(argv_cmd, ' ');
	path_arr = ft_split(env[i] + 5, ':');
	path = check_path(path_arr, cmd_arr[0], env[i]);
	if (!path)
	{
		perror(cmd_arr[0]);
		make_arr_free(path_arr, cmd_arr);
		exit(127);
	}
	if (execve(path, cmd_arr, env) == -1)
	{
		make_arr_free(path_arr, cmd_arr);
		perror(path);
		free(path);
		exit(1);
	}
}

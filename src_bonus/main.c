/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:20:40 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 23:29:40 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_child(char *stop, int fd)
{
	char	*str;

	stop = ft_strjoin(stop, "\n");
	write(0, "pipex here_doc> ", 16);
	str = get_next_line(0);
	while (str != NULL && ft_strncmp(stop, str, ft_strlen(stop)) != 0)
	{			
		write(fd, str, ft_strlen(str));
		free(str);
		write(0, "pipex here_doc> ", 16);
		str = get_next_line(0);
	}
	free(str);
	free(stop);
	exit(0);
}

void	here_doc(char *stop)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		error_exit("Pipe failed");
	pid = fork();
	if (pid == -1)
		error_exit("Fork error");
	if (pid == 0)
		here_doc_child(stop, fd[1]);
	else
	{	
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (waitpid(pid, NULL, 0) == -1)
			error_exit("Waitpid error");
	}
}

t_pipex	*init_struct(int argc, char **argv, char **env, t_pipex *pip)
{
	pip->arc = argc;
	pip->arv = argv;
	pip->env = env;
	return (pip);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_pipex	pip;

	init_struct(argc, argv, env, &pip);
	if (argc >= 5)
	{
		if (argc >= 6 && ft_strncmp("here_doc", argv[1], 9) == 0)
		{
			i = 3;
			here_doc(argv[2]);
		}
		else
			i = 2;
		while (i < argc - 1)
		{
			pipex(&pip, i);
			i++;
		}
		return (0);
	}
	else
	{
		write(1, "Wrong arguments number\n", 23);
		return (1);
	}
}

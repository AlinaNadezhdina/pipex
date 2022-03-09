/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:53:15 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 23:22:30 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc1(int *fds, char **arv, char **env)
{
	int	filein;

	filein = open(arv[0], O_RDONLY, 0644);
	if (filein != -1)
	{
		dup2(filein, STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		close(filein);
		close(fds[1]);
		execute_command(arv[1], env);
	}
	else
	{
		close(fds[0]);
		close(fds[1]);
		error_exit(arv[0]);
	}	
}

void	child_proc2(int *fds, char **arv, char **env, int arc)
{
	int	fileout;

	fileout = open(arv[arc - 1], O_WRONLY + O_TRUNC + O_CREAT, 0644);
	if (fileout != -1)
	{
		dup2(fileout, STDOUT_FILENO);
		dup2(fds[0], STDIN_FILENO);
		close(fds[1]);
		close(fds[0]);
		close(fileout);
		execute_command(arv[arc - 2], env);
	}
	else
	{
		close(fds[1]);
		close(fds[0]);
		error_exit(arv[arc]);
	}	
}

void	pipex(int arc, char **arv, char **env)
{
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fds) == -1)
		error_exit("Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("Fork error");
	if (pid1 == 0)
		child_proc1(fds, arv, env);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("Fork error");
	if (pid2 == 0)
		child_proc2(fds, arv, env, arc);
	close(fds[0]);
	close(fds[1]);
	if (waitpid(pid1, NULL, 0) == -1)
		error_exit("Waitpid pid1 error");
	if (waitpid(pid2, NULL, 0) == -1)
		error_exit("Waitpid pid2 error");
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		write(1, "Wrong arguments number\n", 23);
		return (1);
	}		
	pipex(argc - 1, &argv[1], env);
	return (0);
}

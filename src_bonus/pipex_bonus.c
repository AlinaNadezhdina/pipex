/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:53:15 by wcollen           #+#    #+#             */
/*   Updated: 2022/03/09 23:32:23 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_proc(t_pipex *pip, int *fds, int i)
{
	int	filein;

	close(fds[0]);
	if (i == (pip->arc - 2))
		exit (1);
	if (i == 2)
	{
		filein = open(pip->arv[1], O_RDONLY, 0644);
		if (filein != -1)
		{
			dup2(filein, STDIN_FILENO);
			close(filein);
		}
		else
			error_exit(pip->arv[0]);
	}
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	execute_command(pip->arv[i], pip->env);
}

void	parent_proc(t_pipex *pip, int *fds, int i, int pid)
{
	int	fileout;

	close(fds[1]);
	if (i == (pip->arc - 2))
	{
		waitpid(pid, NULL, 0);
		fileout = open_out_file(pip->arc, pip->arv);
		if (fileout != -1)
		{
			dup2(fileout, STDOUT_FILENO);
			close(fileout);
			execute_command(pip->arv[pip->arc - 2], pip->env);
		}
		else
			error_exit(pip->arv[pip->arc - 1]);
	}
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
}

void	pipex(t_pipex *pip, int i)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		error_exit("Pipe failed");
	pid = fork();
	if (pid == -1)
		error_exit("Fork error");
	if (pid == 0)
		child_proc(pip, fds, i);
	else
		parent_proc(pip, fds, i, pid);
}

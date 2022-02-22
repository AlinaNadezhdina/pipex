/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:53:15 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/21 18:52:20 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *str)
{
	perror(str);
	exit(1);
}

void	child_proc1()
{

}

void	pipex()
{
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fds) == -1)
		error_exit("Pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("Fork error");
	child_proc1();
	


}

//При успехе pipe возвращает значение 0. При отказе, -1
int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		in;
	int		out;

	if (argc != 5)
		return (0);
	
	/* Создаем дочерний процесс. */
	pid = fork();
	if (pid == (pid_t)0)//дочерний процесс создался
	{
		//чтение из pipe
		// read_from_pipe (mypipe[0]);
        // return EXIT_SUCCESS;
	}
	else if (pid < (pid_t) 0)
	{
		//perror("fork"); /* произошла ошибка */
		write (1, "fork error", 10);
		exit(1); /*выход из родительского процесса*/
	}
	
}
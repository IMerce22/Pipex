/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:18:46 by insoares          #+#    #+#             */
/*   Updated: 2024/10/28 11:35:32 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_handler(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit (EXIT_FAILURE);
}

void	child_process(char **av, int *p, char **env)
{
	int	open_fd;

	close(p[0]);
	open_fd = open(av[1], O_RDONLY, 0777);
	if (open_fd < 0)
	{
		perror("Child Process error: open() file!");
		ft_close(p);
		exit (EXIT_FAILURE);
	}
	dup2(open_fd, STDIN_FILENO);
	close(open_fd);
	dup2(p[1], STDOUT_FILENO);
	close(p[1]);
	ft_exec(av[2], env, p);
}

void	child_process_2(char **av, char **env, int *p)
{
	int	open_fd;

	(void)env;
	close(p[1]);
	open_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (open_fd < 0)
	{
		perror("child_process_2 error: open() file!");
		ft_close(p);
		exit (EXIT_FAILURE);
	}
	dup2(open_fd, STDOUT_FILENO);
	close(open_fd);
	dup2(p[0], STDIN_FILENO);
	close(p[0]);
	ft_exec(av[3], env, p);
}

void	ft_child_process_2(char **av, char **env, int *p)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		ft_close(p);
	}
	else if (pid == 0)
		child_process_2(av, env, p);
}

int	main(int ac, char **av, char **env)
{
	int		p[2];
	pid_t	pid;

	if (ac == 5)
	{
		pipe(p);
		if (pipe(p) == -1)
			perror("Pipe");
		pid = fork();
		if (pid == -1)
		{
			perror("Fork");
			ft_close(p);
		}
		else if (pid == 0)
			child_process(av, p, env);
		else
			ft_child_process_2(av, env, p);
		waitpid(0, NULL, 0);
	}
	else
		exit_handler(1);
}

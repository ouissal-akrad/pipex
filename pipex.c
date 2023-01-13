/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:34:23 by ouakrad           #+#    #+#             */
/*   Updated: 2023/01/13 20:37:10 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_leaks(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

void	execution(char *av[], char **env, int i)
{
	char	*path;
	char	**w_args;
	char	*cmd;

	if (av[i])
	{
		w_args = ft_split(av[i], ' ');
		if (!w_args || !w_args[0])
			return ;
		cmd = w_args[0];
		path = find_path(cmd, env);
		execve(path, w_args, env);
		free_leaks(w_args);
	}
	return ;
}

void	first(char *av[], char **env, int pfd[2])
{
	int	fd_c1;

	fd_c1 = open(av[1], O_RDONLY);
	if (fd_c1 < 0)
	{
		close(pfd[0]);
		close(pfd[1]);
		return (perror("open: "));
	}
	dup2(fd_c1, 0);
	dup2(pfd[1], 1);
	close(pfd[0]);
	close(pfd[1]);
	close(fd_c1);
	execution(av, env, 2);
}

void	second(char *av[], char **env, int pfd[2])
{
	int	fd_c2;

	fd_c2 = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_c2 < 0)
	{
		close(pfd[0]);
		close(pfd[1]);
		return (perror("open: "));
	}
	dup2(fd_c2, 1);
	dup2(pfd[0], 0);
	close(pfd[0]);
	close(pfd[1]);
	close(fd_c2);
	execution(av, env, 3);
}

void	pipex(char *av[], char **env)
{
	int	pfd[2];
	int	id;
	int	pid;

	pipe(pfd);
	id = fork();
	if (id < 0)
		return (perror("Fork: "));
	if (id == 0)
		first(av, env, pfd);
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	if (pid == 0)
		second(av, env, pfd);
	close(pfd[0]);
	close(pfd[1]);
	wait (NULL);
	wait (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:51:19 by ouakrad           #+#    #+#             */
/*   Updated: 2023/01/05 22:24:19 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char *av[], char *env[])
{
	int i;
	char *path;
	char **w_args;
	int j;
	char *cmd;
	char *cmd_wargs;

	j = 0;
	i = 1;

	if (av[i])
	{
		if(ft_strchr(av[i],' '))
		{
			w_args = ft_split(av[i], ' ');
			if (!w_args || !w_args[0])
				return (1);
			cmd = w_args[j];
			cmd_wargs = w_args[j + 1];
			char *newargv[] = {cmd , cmd_wargs, NULL};
			path = find_path(cmd ,env);
			execve(path, newargv, env);
		}
		else
		{
			path = find_path(av[i] ,env);
			execve(path, &av[i], env);
		}
	}
	return (0);
}

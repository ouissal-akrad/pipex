/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:54:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/01/03 19:24:26 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(char *path, char *cmd)
{
	char	**paths;
	char 	*new_path;
	char	*tmp;
	int		i;

	paths = ft_split(path, ':');
	if (!paths)
		return ft_printf(printf("Memorry Error"), NULL);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if(!tmp)
			return(free_leaks(paths), NULL);
		new_path = ft_strjoin(tmp, cmd);
		if(!new_path)
			return(free_leaks(paths), free(tmp),NULL);
		free(tmp);
		if (access(new_path, F_OK) == 0)
		{
			free_leaks(paths);
			return (new_path);
		}
		free(new_path);
	}
	free_leaks(paths);
	return (NULL);
}

char	*find_path(char *cmd, char *envp[])
{
	char *result;
	int	i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) != 0)
			return (ft_printf("Command not found!"), NULL);
		cmd = ft_strdup(cmd);
		if (!cmd)
			return (ft_printf("Memorry Error"), NULL);
		return (cmd);
	}
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			result = (envp[i], cmd);
			return (result);
		}
	}
	return (NULL);
}

int main(int argc,char **argv ,char **env)
{
	char *t = find_path("ls",env);
	ft_printf("%s",t);
	system("leaks a.out");
}

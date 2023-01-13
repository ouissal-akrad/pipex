/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:54:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/01/12 23:55:56 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(char *path, char *cmd)
{
	char	**paths;
	char	*new_path;
	char	*tmp;
	int		i;

	paths = ft_split(path, ':');
	if (!paths)
		return (write(2, "Memorry Error!\n", 15), NULL);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (free_leaks(paths), NULL);
		new_path = ft_strjoin(tmp, cmd);
		if (!new_path)
			return (free_leaks(paths), free(tmp), NULL);
		free(tmp);
		if (access(new_path, X_OK) == 0)
			return (free_leaks(paths), new_path);
		free(new_path);
	}
	free_leaks(paths);
	return (NULL);
}

char	*find_path(char *cmd, char *envp[])
{
	int	i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) != 0)
			return (write(2, "Command not found!\n", 20), NULL);
		cmd = ft_strdup(cmd);
		if (!cmd)
			return (write(2, "Memorry Error!\n", 15), NULL);
		return (cmd);
	}
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (join_path(envp[i] + 5, cmd));
		}
	}
	return (NULL);
}

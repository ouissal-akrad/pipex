/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:18:40 by ouakrad           #+#    #+#             */
/*   Updated: 2023/01/13 20:32:32 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*join_path(char *path, char *cmd);
char	*find_path(char *cmd, char *envp[]);
void	free_leaks(char **paths);
void	execution(char *av[], char **env, int i);
void	pipex(char *av[], char **env);
void	second(char *av[], char **env, int pfd[2]);
void	first(char *av[], char **env, int pfd[2]);

#endif

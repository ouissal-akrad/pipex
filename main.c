/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:51:19 by ouakrad           #+#    #+#             */
/*   Updated: 2023/01/13 20:32:37 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	if (!env[0])
		return (write(2, "Error!\n", 7), 1);
	if (ac != 5)
		write (2, "Should behave like : ./pipex infile cmd1 cmd2 outfile\n", 55);
	else if (ac == 5)
		pipex(av, env);
	return (0);
}

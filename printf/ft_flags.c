/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:05:09 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/08 16:35:32 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_flags(va_list args, const char *str, int i, int *count)
{
	if (str[i + 1] == '#' || str[i + 1] == ' ' || str[i + 1] == '+')
	{
		while ((str[i + 1] == '#' || str[i + 1] == ' ' || str[i + 1] == '+'))
			i++;
		ft_plus(va_arg(args, int), count);
		i++;
	}
	else
	{
		ft_format(args, str, &i, &count);
	}
}

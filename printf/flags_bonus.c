/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:05:09 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/12 05:25:20 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ft_printf_bonus.h"

int	ft_flags(va_list args, const char *str, int i, int *count)
{
	if (str[i] == ' ' || str[i] == '+' || str[i] == '#')
	{
		while ((str[i] == ' ' || str[i] == '+' || str[i] == '#'))
			i++;
		if (str[i - 1] == '+' && (str[i] == 'd' || str[i] == 'i'))
			ft_plus(va_arg(args, int), count);
		else if (str[i - 1] == ' ' && str[i] == 's')
			ft_putstr(va_arg(args, char *), count);
		else if (str[i - 1] == ' ' && (str[i] == 'd' || str[i] == 'i'))
			ft_space(va_arg(args, int), count);
		else if ((str[i - 1] == '#' && (str[i] == 'X' || str[i] == 'x')))
		{
			if (str[i] == 'X')
				ft_hashmaj(va_arg(args, unsigned int), "0123456789ABCDEF",
					count); 
			else if (str[i] == 'x')
				ft_hashmin(va_arg(args, unsigned int), "0123456789abcdef",
					count);
		}
	}
	else
		ft_format(args, str, i, count);
	return (i);
}

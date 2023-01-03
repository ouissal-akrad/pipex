/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:10:38 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/18 21:51:13 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int check_format(const char *str, int i)
{
	char *format;
	int j;

	j = 0;
	format = "scpdiuxX# +";
	while (format[j])
	{
		if (str[i] == format[j])
			return (0);
		j++;
	}
	return (1);
}

int ft_printf(const char *str, ...)
{
	int i;
	int count;
	va_list args;

	i = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &count);
		else if (check_format(str, i + 1))
		{
			if (str[i + 1] == '\0')
				break;
			ft_putchar(str[i + 1], &count);
			i++;
		}
		else
			i = ft_flags(args, str, i + 1, &count);
		i++;
	}
	va_end(args);
	return (count);
}

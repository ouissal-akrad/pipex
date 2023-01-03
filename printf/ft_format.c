/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:49:19 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/16 22:20:08 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_format(va_list args, const char *str, int i, int *count)
{
	if (str[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	if (str[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	if (str[i] == 'p')
	{
		ft_putstr("0x", count);
		ft_putadress(va_arg(args, unsigned long long), "0123456789abcdef",
			count);
	}
	if (str[i] == 'd')
		ft_putnbr(va_arg(args, int), count);
	if (str[i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	if (str[i] == 'u')
		ft_putunsigned(va_arg(args,int), count);
	if (str[i] == 'x')
		ft_puthexa(va_arg(args, unsigned int long), "0123456789abcdef", count);
	if (str[i] == 'X')
		ft_puthexa(va_arg(args, unsigned int long), "0123456789ABCDEF", count);
	if (str[i] == '%')
		ft_putchar('%', count);
}

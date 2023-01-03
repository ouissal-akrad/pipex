/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:17:11 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/08 12:30:50 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', count);
		ft_putchar('2', count);
		ft_putnbr(147483648, count);
	}
	else if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
		ft_putnbr(nb, count);
	}
	else if (nb > 9)
		ft_putunsigned(nb, count);
	else
		ft_putchar(nb + 48, count);
}

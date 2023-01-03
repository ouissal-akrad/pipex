/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:45:59 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/10 14:18:18 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_plus(int nb, int *count)
{
	if (nb == -2147483648)
		ft_putnbr(nb, count);
	else if (nb < 0)
		ft_putnbr(nb, count);
	else if (nb > 9)
	{
		ft_putchar('+', count);
		ft_putunsigned(nb, count);
	}
	else
	{
		ft_putchar('+', count);
		ft_putchar(nb + 48, count);
	}
}

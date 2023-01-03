/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:17:03 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/08 11:41:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_space(int nb, int *count)
{
	if (nb == -2147483648)
		ft_putnbr(nb, count);
	else if (nb < 0)
		ft_putnbr(nb, count);
	else if (nb > 9)
	{
		ft_putchar(' ', count);
		ft_putunsigned(nb, count);
	}
	else
	{
		ft_putchar(' ', count);
		ft_putchar(nb + 48, count);
	}
}

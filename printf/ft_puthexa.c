/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:55:52 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/09 19:37:28 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_puthexa(unsigned int nb, const char *base, int *count)
{
	if (nb < 16)
	{
		ft_putchar(base[nb], count);
	}
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, base, count);
		ft_putchar(base[nb % 16], count);
	}
}

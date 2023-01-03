/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmaj_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:58:04 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/10 14:18:07 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_hashmaj(unsigned int nb, const char *base, int *count)
{
	if (nb == 0)
		ft_putchar('0', count);
	else
	{
		ft_putstr("0X", count);
		ft_puthexa(nb, base, count);
	}
}

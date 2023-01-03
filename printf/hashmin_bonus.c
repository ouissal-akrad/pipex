/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmin_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:39:28 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/10 14:18:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_bonus.h"

void	ft_hashmin(unsigned int nb, const char *base, int *count)
{
	if (nb == 0)
		ft_putchar('0', count);
	else
	{
		ft_putstr("0x", count);
		ft_puthexa(nb, base, count);
	}
}

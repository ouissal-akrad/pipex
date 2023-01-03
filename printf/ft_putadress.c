/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:57:22 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/09 19:09:18 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putadress(unsigned long long nb, const char *base, int *count)
{
	if (nb >= 16)
		ft_putadress(nb / 16, base, count);
	ft_putchar(base[nb % 16], count);
}

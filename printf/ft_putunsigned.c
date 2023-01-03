/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:49:29 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/08 12:30:57 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putunsigned(unsigned int nb, int *count)
{
	if (nb > 9)
	{
		ft_putunsigned(nb / 10, count);
		ft_putunsigned(nb % 10, count);
	}
	else
		ft_putchar(nb + 48, count);
}

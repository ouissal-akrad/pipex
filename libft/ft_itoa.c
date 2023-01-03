/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:41:41 by ouakrad           #+#    #+#             */
/*   Updated: 2022/10/29 17:45:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fill(char *str, long n, int count)
{
	int	nitem;

	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	nitem = count - 1;
	while (nitem >= 0 && str[nitem] != '-')
	{
		str[nitem--] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;

	count = ft_count(n);
	str = (char *)ft_calloc((count + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_fill(str, n, count);
	return (str);
}

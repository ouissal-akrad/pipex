/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:42:05 by ouakrad           #+#    #+#             */
/*   Updated: 2022/10/29 12:25:52 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_dest;
	char	*tmp_src;
	size_t	i;

	i = -1;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	if (dest > src)
	{
		while (n)
		{
			tmp_dest[n - 1] = tmp_src[n - 1];
			n--;
		}
	}
	else
	{
		while (++i < n)
			tmp_dest[i] = tmp_src[i];
	}
	return (dest);
}

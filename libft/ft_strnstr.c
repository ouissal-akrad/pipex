/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:42:41 by ouakrad           #+#    #+#             */
/*   Updated: 2022/10/29 18:42:23 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if ((!s || !to_find) && n == 0)
		return (NULL);
	if (*to_find == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] && i < n)
	{
		if (s[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] && to_find[j] == s[i + j] && i + j < n)
				j++;
			if (!to_find[j])
				return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

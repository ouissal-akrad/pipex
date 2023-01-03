/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:38:47 by ouakrad           #+#    #+#             */
/*   Updated: 2022/10/26 18:42:16 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	actual_len;
	char	*pnt;

	if (!s)
		return (NULL);
	actual_len = ft_strlen(s);
	if (start >= actual_len)
		start = actual_len;
	if (len > actual_len - start)
		len = actual_len - start;
	pnt = (char *) malloc(sizeof(*s) * (len + 1));
	if (!pnt)
		return (NULL);
	i = 0;
	while (i < len)
		pnt[i++] = s[start++];
	pnt[i] = '\0';
	return (pnt);
}

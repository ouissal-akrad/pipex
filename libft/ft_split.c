/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:04:48 by ouakrad           #+#    #+#             */
/*   Updated: 2022/10/31 17:00:45 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	count_char(char *s, char c)
{
	int	count_char;
	int	i;

	count_char = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		count_char++;
	}
	return (count_char);
}

static	int	split1(char *s, char c, char **resultat)
{
	int	i;
	int	j;
	int	mot;
	int	pos_char;

	i = 0;
	mot = 0;
	pos_char = 0;
	while (s[i] != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = count_char(&s[i], c);
		resultat[mot] = (char *)malloc(j + 1);
		if (!resultat)
			return (mot);
		while (pos_char < j)
			resultat[mot][pos_char++] = s[i++];
		resultat[mot++][pos_char] = 0;
		pos_char = 0;
	}
	resultat[mot] = 0;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	int		r;
	char	**resultat;
	int		count;

	if (!s)
		return (NULL);
	count = count_word((char *)s, c);
	resultat = malloc(sizeof(char *) * (count + 1));
	if (!resultat)
		return (NULL);
	r = split1((char *)s, c, resultat);
	if (r == -1)
		return (resultat);
	else
	{
		while (r >= 0)
			free(resultat[r--]);
		free(resultat);
	}
	return (NULL);
}

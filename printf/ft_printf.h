/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:03:15 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/10 14:15:47 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putunsigned(unsigned int nb, int *count);
void	ft_puthexa(unsigned int nb, const char *base, int *count);
void	ft_putadress(unsigned long long nb, const char *base, int *count);
void	ft_format(va_list args, const char *str, int i, int *count);
int		ft_printf(const	char *str, ...);
int		ft_flags(va_list args, const char *str, int i, int *count);

#endif

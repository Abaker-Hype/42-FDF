/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:25:18 by abaker            #+#    #+#             */
/*   Updated: 2021/11/05 16:19:55 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printint(char *str, bool neg, t_flags *flags)
{
	int	printlen;
	int	strlen;

	printlen = 0;
	strlen = ft_strlen(str);
	if (neg && !flags->zero)
		printlen += write(1, "-", 1);
	else if (!neg && !flags->zero && flags->plus)
		printlen += write(1, "+", 1);
	else if (!neg && !flags->zero && flags->space)
		printlen += write(1, " ", 1);
	if (flags->dot >= 0)
		printlen += ft_formatwidth(flags->dot - 1, strlen - 1, true);
	printlen += ft_printstr(str, strlen);
	return (printlen);
}

static int	ft_formatintprint(char *str, bool neg, t_flags *flags)
{
	int	printlen;
	int	strlen;

	printlen = 0;
	strlen = ft_strlen(str);
	if (flags->minus)
		printlen += ft_printint(str, neg, flags);
	if (flags->dot >= 0 && flags->dot < strlen)
		flags->dot = strlen;
	if (flags->plus || (flags->space && flags->minus))
		flags->width--;
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		printlen += ft_formatwidth(flags->width, 0, false);
	}
	else
		printlen += ft_formatwidth(flags->width, strlen, flags->zero);
	if (!flags->minus)
		printlen += ft_printint(str, neg, flags);
	return (printlen);
}

int	ft_handleint(int n, t_flags *flags)
{
	int				printlen;
	unsigned int	un;
	char			*str;

	printlen = 0;
	if (flags->dot == 0 && n == 0)
		return (ft_formatwidth(flags->width, 0, false));
	if (n < 0)
	{
		if (flags->zero && flags->dot == -1)
			printlen += write(1, "-", 1);
		flags->width--;
		un = n * -1;
	}
	else
		un = n;
	str = ft_numtobase(un, "0123456789", false);
	printlen += ft_formatintprint(str, n < 0, flags);
	free(str);
	return (printlen);
}

int	ft_handleuint(unsigned int n, t_flags *flags)
{
	int		printlen;
	char	*str;

	printlen = 0;
	if (flags->dot == 0 && n == 0)
		return (ft_formatwidth(flags->width, 0, false));
	str = ft_numtobase(n, "0123456789", false);
	printlen += ft_formatintprint(str, false, flags);
	free(str);
	return (printlen);
}

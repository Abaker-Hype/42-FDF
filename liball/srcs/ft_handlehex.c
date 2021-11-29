/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlehex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:27:33 by abaker            #+#    #+#             */
/*   Updated: 2021/09/16 13:46:10 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex(char *str, int strlen, bool cap, t_flags *flags)
{
	int	printlen;

	printlen = 0;
	if (flags->hash)
	{
		if (cap)
			printlen += write(1, "0X", 2);
		else
			printlen += write(1, "0x", 2);
	}
	if (flags->dot >= 0)
		printlen += ft_formatwidth(flags->dot - 1, strlen - 1, true);
	printlen += ft_printstr(str, strlen);
	return (printlen);
}

static int	ft_formathexprint(char *str, bool cap, t_flags *flags)
{
	int	printlen;
	int	strlen;

	printlen = 0;
	strlen = ft_strlen(str);
	if (flags->minus)
		printlen += ft_printhex(str, strlen, cap, flags);
	if (flags->dot >= 0 && flags->dot < strlen)
		flags->dot = strlen;
	if (flags->hash)
		flags->width -= 2;
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		printlen += ft_formatwidth(flags->width, 0, false);
	}
	else
		printlen += ft_formatwidth(flags->width, strlen, flags->zero);
	if (!flags->minus)
		printlen += ft_printhex(str, strlen, cap, flags);
	return (printlen);
}

int	ft_handlehex(unsigned int n, t_flags *flags, bool cap)
{
	int		printlen;
	char	*str;

	printlen = 0;
	if (flags->dot == 0 && n == 0)
		return (ft_formatwidth(flags->width, 0, false));
	if (n == 0)
		flags->hash = false;
	str = ft_numtobase((unsigned long long)n, "0123456789abcdef", cap);
	printlen += ft_formathexprint(str, cap, flags);
	free(str);
	return (printlen);
}

int	ft_handlepointer(unsigned long long ptr, t_flags *flags)
{
	int		printlen;
	char	*str;

	printlen = 0;
	if (flags->dot == 0 && ptr == 0)
		return (ft_formatwidth(flags->width, 0, false));
	flags->hash = true;
	str = ft_numtobase(ptr, "0123456789abcdef", false);
	printlen += ft_formathexprint(str, false, flags);
	free(str);
	return (printlen);
}

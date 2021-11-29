/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:27:56 by abaker            #+#    #+#             */
/*   Updated: 2021/09/16 13:28:01 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formatstrprint(char *str, int strlen, t_flags *flags)
{
	int	printlen;

	printlen = 0;
	if (flags->dot >= 0)
	{
		printlen += ft_formatwidth(flags->dot, strlen, flags->zero);
		printlen += ft_printstr(str, flags->dot);
	}
	else
		printlen += ft_printstr(str, strlen);
	return (printlen);
}

int	ft_handlestr(char *str, t_flags *flags)
{
	int	printlen;
	int	strlen;

	printlen = 0;
	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (flags->dot - strlen > 0)
		flags->dot = strlen;
	if (flags->minus)
		printlen += ft_formatstrprint(str, strlen, flags);
	if (flags->dot >= 0)
		printlen += ft_formatwidth(flags->width, flags->dot, flags->zero);
	else
		printlen += ft_formatwidth(flags->width, strlen, flags->zero);
	if (!flags->minus)
		printlen += ft_formatstrprint(str, strlen, flags);
	return (printlen);
}

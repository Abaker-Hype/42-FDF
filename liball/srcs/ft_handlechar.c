/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:27:20 by abaker            #+#    #+#             */
/*   Updated: 2021/09/16 13:27:22 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handlechar(int c, t_flags *flags)
{
	int	printlen;

	printlen = 0;
	if (flags->minus)
		printlen += write(1, &c, 1);
	printlen += ft_formatwidth(flags->width, 1, flags->zero);
	if (!flags->minus)
		printlen += write(1, &c, 1);
	return (printlen);
}

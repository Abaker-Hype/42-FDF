/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatwidth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:26:51 by abaker            #+#    #+#             */
/*   Updated: 2021/09/16 13:26:55 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatwidth(int width, int strlen, bool zero)
{
	int	printlen;

	printlen = 0;
	while (width - strlen > printlen)
	{
		if (zero)
			printlen += write(1, "0", 1);
		else
			printlen += write(1, " ", 1);
	}
	return (printlen);
}

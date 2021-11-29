/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handletype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:28:17 by abaker            #+#    #+#             */
/*   Updated: 2021/11/17 10:05:38 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handletype(t_flags *flags, va_list args)
{
	char	c;

	c = flags->type;
	if (c == 'c')
		return (ft_handlechar(va_arg(args, int), flags));
	else if (c == 's')
		return (ft_handlestr(va_arg(args, char *), flags));
	else if (c == 'i' || c == 'd')
		return (ft_handleint(va_arg(args, int), flags));
	else if (c == 'u')
		return (ft_handleuint(va_arg(args, unsigned int), flags));
	else if (c == 'p')
		return (ft_handlepointer(va_arg(args, unsigned long long), flags));
	else if (c == 'x' || c == 'X')
		return (ft_handlehex(va_arg(args, unsigned int), flags, c == 'X'));
	return (0);
}

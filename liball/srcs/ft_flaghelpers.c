/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaghelpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:26:36 by abaker            #+#    #+#             */
/*   Updated: 2021/11/17 10:06:46 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_istype(char c)
{
	return (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == 'u'
		|| c == 'p' || c == 'x' || c == 'X' || c == '%');
}

bool	ft_isflag(char c)
{
	return (c == '#' || c == '0' || c == ' ' || c == '+' || c == '-'
		|| c == '.');
}

int	ft_flagdot(const char *str, int i, t_flags *flags)
{
	i++;
	flags->dot = 0;
	while (ft_isdigit(str[i]))
	{
		flags->dot = (flags->dot * 10) + (str[i] - '0');
		i++;
	}
	if (!ft_istype(str[i]))
		flags->error = true;
	return (i);
}

int	ft_flagwidth(const char *str, int i, t_flags *flags)
{
	while (ft_isdigit(str[i]))
	{
		flags->width = (flags->width * 10) + (str[i] - '0');
		i++;
	}
	if (!(ft_istype(str[i]) || str[i] == '.'))
		flags->error = true;
	return (i);
}

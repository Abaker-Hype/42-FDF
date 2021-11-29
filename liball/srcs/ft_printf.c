/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:25:04 by abaker            #+#    #+#             */
/*   Updated: 2021/11/08 14:47:48 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_defaultflags(void)
{
	t_flags	flags;

	flags.type = '\0';
	flags.hash = false;
	flags.minus = false;
	flags.plus = false;
	flags.space = false;
	flags.zero = false;
	flags.width = 0;
	flags.dot = -1;
	flags.error = false;
	return (flags);
}

static void	ft_getflag(const char *str, int i, t_flags *flags)
{
	if (str[i] == '.')
		return ;
	else if (str[i] == '#')
		flags->hash = true;
	else if (str[i] == '0' && !flags->minus)
		flags->zero = true;
	else if (str[i] == ' ' && !flags->plus)
		flags->space = true;
	else if (str[i] == '+')
	{
		flags->plus = true;
		flags->space = false;
	}
	else if (str[i] == '-')
	{
		flags->minus = true;
		flags->zero = false;
	}
}

static int	ft_parseflags(const char *str, int start, t_flags *flags)
{
	int	i;

	i = start;
	while (str[i] != '\0' && !flags->error)
	{
		i++;
		if (str[i] == '\0' || !(ft_istype(str[i]) || ft_isflag(str[i])
				|| ft_isdigit(str[i])))
			break ;
		if (ft_isflag(str[i]))
			ft_getflag(str, i, flags);
		if (ft_isdigit(str[i]) && str[i] != '0')
			i = ft_flagwidth(str, i, flags);
		if (str[i] == '.')
			i = ft_flagdot(str, i, flags);
		if (ft_istype(str[i]) && !flags->error)
		{
			flags->type = str[i];
			return (i);
		}
	}
	return (start + 1);
}

static int	ft_parsestr(char *str, va_list args)
{
	t_flags	flags;
	int		printlen;
	int		i;

	i = 0;
	printlen = 0;
	while (str[i] != '\0')
	{
		flags = ft_defaultflags();
		if (str[i] == '%')
			i = ft_parseflags(str, i, &flags);
		if (flags.type == '%')
			printlen += write(1, "%", 1);
		else if (flags.type != '\0')
			printlen += ft_handletype(&flags, args);
		else if (str[i] != '\0')
			printlen += write(1, &str[i], 1);
		i++;
	}
	return (printlen);
}

int	ft_printf(const char *str, ...)
{
	char	*copy;
	va_list	args;
	int		printlen;

	copy = ft_strdup(str);
	va_start(args, str);
	printlen = ft_parsestr(copy, args);
	va_end(args);
	free(copy);
	return (printlen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtobase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:29:24 by abaker            #+#    #+#             */
/*   Updated: 2021/11/05 16:19:16 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countdigits(unsigned long long n, unsigned long long baselen)
{
	int	count;

	count = 1;
	while (n >= baselen)
	{
		n /= baselen;
		count++;
	}
	return (count);
}

char	*ft_numtobase(unsigned long long n, char *base, bool cap)
{
	char	*str;
	int		digits;
	int		baselen;

	baselen = ft_strlen(base);
	digits = ft_countdigits(n, baselen);
	str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (digits > 0)
	{
		digits--;
		str[digits] = base[(n % baselen)];
		if (cap && str[digits] >= 'a' && str[digits] <= 'z')
			str[digits] -= 32;
		n /= baselen;
	}	
	return (str);
}

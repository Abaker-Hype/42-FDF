/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:38:10 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 11:38:17 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*getdecimals(char *dest, double n, int places)
{
	int	i;

	i = 1;
	dest[0] = '.';
	if (n < 0)
		n *= -1;
	while (i <= places)
	{
		n *= 10;
		dest[i] = '0' + ((int)n % 10);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_ftoa(double n, int places)
{
	char	*str;
	char	*intstr;
	char	*decstr;

	if (places <= 0)
		return (ft_itoa((int)n));
	if (places > 7)
		places = 7;
	decstr = malloc(sizeof(char) * (places + 2));
	if (!decstr)
		return (NULL);
	intstr = ft_itoa((int)n);
	decstr = getdecimals(decstr, n, places);
	str = ft_strjoin(intstr, decstr);
	free(intstr);
	free(decstr);
	return (str);
}

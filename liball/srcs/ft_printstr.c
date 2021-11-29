/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:29:09 by abaker            #+#    #+#             */
/*   Updated: 2021/09/16 13:29:11 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, int maxprint)
{
	if ((int)ft_strlen(str) < maxprint)
		maxprint = ft_strlen(str);
	return (write(1, str, maxprint));
}

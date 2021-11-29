/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:13:07 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 19:13:13 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	deg2rad(double deg)
{
	return (deg * (M_1_PI / 18));
}

void	updatemath(void)
{
	g_math()->sinx = sin(deg2rad(g_settings()->rotx));
	g_math()->cosx = cos(deg2rad(g_settings()->rotx));
	g_math()->siny = sin(deg2rad(g_settings()->roty));
	g_math()->cosy = cos(deg2rad(g_settings()->roty));
}

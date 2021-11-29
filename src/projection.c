/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:00:49 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 15:03:13 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector	offsetscale(t_vector v)
{
	v.x += g_settings()->offsetx;
	v.y += g_settings()->offsety;
	v.x = (g_map2d()->panel.width / 2) + (v.x * g_settings()->scale);
	v.y = (g_map2d()->panel.height / 2) + (v.y * g_settings()->scale);
	return (v);
}

t_vector	parallel(t_vector v)
{
	t_vector	iso;
	t_math		*math;

	math = g_math();
	iso.x = (v.x * math->cosx) - (v.z * math->sinx);
	iso.y = (v.y * math->cosy) + (v.x * math->siny * math->sinx)
		+ (v.z * math->siny * math->cosx);
	iso.z = 0.0;
	iso.rgb = v.rgb;
	return (offsetscale(iso));
}

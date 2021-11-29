/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatesettings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:13:35 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 19:13:37 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	updaterot(int key)
{
	if (key == XK_LEFT || key == XK_RIGHT)
		g_settings()->rotx += 1 + (-2 * (key == XK_LEFT));
	else
		g_settings()->roty += 1 + (-2 * (key == XK_DOWN));
	updatemath();
}

void	updateoffset(int key)
{
	if (key == XK_A || key == XK_D)
		g_settings()->offsetx += 1 + (-2 * (key == XK_A));
	else
		g_settings()->offsety += 1 + (-2 * (key == XK_W));
}

void	updatescale(int key)
{
	(g_settings())->scale += 1 + (-2 * (key == XK_MINUS || key == XK_NUMMINUS));
}

void	changemap(int key)
{
	if (g_settings()->totalmaps == 1)
		return ;
	if (key == XK_X)
	{
		*g_maps() = (*g_maps())->next;
		g_settings()->currmap++;
	}
	else
	{
		*g_maps() = (*g_maps())->prev;
		g_settings()->currmap--;
	}
	if (g_settings()->currmap == 0)
		g_settings()->currmap = g_settings()->totalmaps;
	if (g_settings()->currmap > g_settings()->totalmaps)
		g_settings()->currmap = 1;
	loadmap2d();
}

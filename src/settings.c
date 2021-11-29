/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:13:22 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 19:13:23 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	addtext(int x, int y, char *str, bool f)
{
	mlx_string_put(g_mlx()->mlx, g_mlx()->win, x, y, 0xFFFFFF, str);
	if (f)
		free(str);
}

static void	settingstext(void)
{
	addtext(90, 10, "Current Map", false);
	addtext(10, 30, (*g_maps())->file, false);
	addtext(10, 70, "Rotate X =", false);
	addtext(120, 70, ft_ftoa(g_settings()->rotx, 3), true);
	addtext(10, 90, "Rotate Y =", false);
	addtext(120, 90, ft_ftoa(g_settings()->roty, 3), true);
	addtext(10, 120, "Offset X =", false);
	addtext(120, 120, ft_ftoa(g_settings()->offsetx, 3), true);
	addtext(10, 140, "Offset Y =", false);
	addtext(120, 140, ft_ftoa(g_settings()->offsety, 3), true);
	addtext(40, 170, "Scale =", false);
	addtext(120, 170, ft_ftoa(g_settings()->scale, 3), true);
	addtext(90, 300, "Controls", false);
	addtext(50, 320, "Rotate = Arrow Keys", false);
	addtext(30, 340, "Move Map = WASD", false);
	addtext(70, 360, "Zoom = - +", false);
	addtext(10, 380, "Reset View = R", false);
	addtext(30, 410, "Next Map = X", false);
	addtext(30, 430, "Prev Map = Z", false);
}

void	defaultsettings(void)
{
	g_settings()->offsetx = 0;
	g_settings()->offsety = 0;
	g_settings()->rotx = 45;
	g_settings()->roty = 45;
	g_settings()->scale = 10;
	updatemath();
}

void	drawsettings(void)
{
	if (g_settings()->panel.img)
		mlx_destroy_image(g_mlx()->mlx, g_settings()->panel.img);
	(g_settings())->panel = newimage(SETTINGS_WIDTH, WIN_HEIGHT);
	colourimage(&g_settings()->panel, int2rgb(0x424242));
	mlx_put_image_to_window(g_mlx()->mlx, g_mlx()->win,
		g_settings()->panel.img, 0, 0);
	settingstext();
}

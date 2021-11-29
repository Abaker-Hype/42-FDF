/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:12:18 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 19:12:20 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loadmap2d(void)
{
	if (g_map2d()->points)
		ft_freearry((void **)g_map2d()->points);
	g_map2d()->width = (*g_maps())->width;
	g_map2d()->height = (*g_maps())->height;
	(g_map2d())->points = vectorarray(g_map2d()->height, g_map2d()->width);
}

static void	convertmap(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_map2d()->height)
	{
		col = 0;
		while (col < g_map2d()->width)
		{
			g_map2d()->points[row][col] = (g_settings()->func)
			((*g_maps())->points[row][col]);
			col++;
		}
		row++;
	}
}

static void	drawmap(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_map2d()->height)
	{
		col = 0;
		while (col < g_map2d()->width)
		{
			if (row + 1 < g_map2d()->height)
				drawline(&(g_map2d()->panel), g_map2d()->points[row][col],
					g_map2d()->points[row +1][col]);
			if (col + 1 < g_map2d()->width)
				drawline(&(g_map2d()->panel), g_map2d()->points[row][col],
					g_map2d()->points[row][col + 1]);
			if (row + 1 < g_map2d()->height && col + 1 < g_map2d()->width)
				drawline(&(g_map2d()->panel), g_map2d()->points[row][col],
					g_map2d()->points[row + 1][col + 1]);
			col++;
		}
		row++;
	}
}

void	render2dmap(void)
{
	if (g_map2d()->panel.img)
		mlx_destroy_image(g_mlx()->mlx, g_map2d()->panel.img);
	(g_map2d())->panel = newimage(WIN_WIDTH - SETTINGS_WIDTH, WIN_HEIGHT);
	convertmap();
	drawmap();
	mlx_put_image_to_window(g_mlx()->mlx, g_mlx()->win, g_map2d()->panel.img,
		SETTINGS_WIDTH, 0);
}

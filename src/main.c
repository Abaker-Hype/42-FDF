/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:30:59 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 15:44:35 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	usage(void)
{
	ft_printf("Please provide 1 or more map files\n");
	return (true);
}

static void	loadmlx(void)
{
	g_mlx()->mlx = mlx_init();
	(g_mlx())->win = mlx_new_window(g_mlx()->mlx,
			WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
}

int	main(int c, char **v)
{
	if ((c == 1 && usage()) || (!initmaps(c, v)))
		return (0);
	loadmlx();
	defaultsettings();
	g_settings()->currmap = 1;
	g_settings()->func = parallel;
	loadmap2d();
	loadhooks();
	drawsettings();
	render2dmap();
	mlx_loop(g_mlx()->mlx);
}

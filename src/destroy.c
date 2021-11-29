/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:13:55 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 19:13:56 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closewin(void)
{
	destroy();
	return (0);
}

static void	freemaps(void)
{
	t_maps	*curr;
	t_maps	*next;

	curr = *g_maps();
	while (curr->next != *g_maps())
	{
		ft_freearry((void **)curr->points);
		next = curr->next;
		free(curr);
		curr = next;
	}
	ft_freearry((void **)curr->points);
	free(curr);
}

void	destroy(void)
{
	if (g_map2d()->panel.img)
		mlx_destroy_image(g_mlx()->mlx, g_map2d()->panel.img);
	if (g_settings()->panel.img)
		mlx_destroy_image(g_mlx()->mlx, g_settings()->panel.img);
	mlx_destroy_window(g_mlx()->mlx, g_mlx()->win);
	if (g_map2d()->points)
		ft_freearry((void **)g_map2d()->points);
	freemaps();
	freehooks();
	free(g_mlx()->mlx);
	exit(0);
}

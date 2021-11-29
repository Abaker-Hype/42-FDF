/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:31:04 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 13:33:35 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	normalizemap(t_maps *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			map->points[row][col].x -= map->width / 2;
			map->points[row][col].y -= map->height / 2;
			map->points[row][col].z -= (map->zmax - map->zmin) / 2;
			col++;
		}
		row++;
	}
}

static t_maps	*newmap(char *file)
{
	t_maps	*new;

	if (!file)
		return (NULL);
	new = ft_calloc(sizeof(t_maps), 1);
	if (!new)
		return (NULL);
	if (!parsemap(new, file))
	{
		free(new);
		return (NULL);
	}
	new->file = ft_strrchr(file, '/') + 1;
	new->next = new;
	new->prev = new;
	normalizemap(new);
	return (new);
}

static bool	addmap(t_maps *new)
{
	if (!new)
		return (false);
	if (!*g_maps())
		*g_maps() = new;
	else
	{
		new->next = (*g_maps());
		new->prev = (*g_maps())->prev;
		(*g_maps())->prev->next = new;
		(*g_maps())->prev = new;
	}
	g_settings()->totalmaps++;
	return (true);
}

bool	initmaps(int n, char **maps)
{
	int	i;

	i = 1;
	g_settings()->totalmaps = 0;
	while (i < n)
	{
		if (!addmap(newmap(maps[i])))
			ft_printf("\nWarning: %s couldn't be parsed\n", maps[i]);
		i++;
	}
	if (g_settings()->totalmaps == 0)
	{
		ft_printf("Error: No maps could be parsed\n");
		return (false);
	}
	return (true);
}

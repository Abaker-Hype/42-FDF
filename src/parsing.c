/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:04:19 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 14:03:13 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static t_vector	*genrow(t_maps *map, char **data)
{
	t_vector	*row;
	int			i;

	if (!data)
		return (NULL);
	if (map->width == 0)
		while (data[map->width])
			map->width++;
	row = ft_calloc(sizeof(t_vector), map->width);
	if (row)
	{
		i = 0;
		while (i < map->width)
		{
			row[i] = newvector(i, map->height, data[i]);
			if (row[i].z > map->zmax)
				map->zmax = row[i].z;
			if (row[i].z < map->zmin)
				map->zmin = row[i].z;
			i++;
		}
	}
	ft_freearry((void **)data);
	return (row);
}

static bool	addrow(t_maps *map, t_vector *row)
{
	t_vector	**tmp;
	int			i;

	if (!row)
		return (false);
	tmp = ft_calloc(sizeof(t_vector *), map->height + 2);
	if (!tmp)
		return (false);
	i = map->height;
	tmp[i] = row;
	while (i-- > 0)
		tmp[i] = map->points[i];
	free(map->points);
	map->points = tmp;
	map->height++;
	return (true);
}

bool	parsemap(t_maps *map, char *file)
{
	int		fd;
	char	*line;

	ft_printf("Parsing Map: %s ...", file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!addrow(map, genrow(map, ft_split(line, ' '))))
		{
			free(line);
			close(fd);
			return (false);
		}
		free(line);
	}
	close(fd);
	ft_printf("Done\n");
	return (true);
}

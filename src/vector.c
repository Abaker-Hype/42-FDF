/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:36:27 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 15:44:37 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	newvector(int x, int y, char *data)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = ft_atoi(data);
	new.rgb = newcolour(ft_strchr(data, ','));
	return (new);
}

t_vector	**vectorarray(int rows, int cols)
{
	t_vector	**arry;

	arry = ft_calloc(sizeof(t_vector *), rows + 1);
	if (!arry)
		return (NULL);
	arry[rows] = NULL;
	while (rows > 0)
	{
		rows--;
		arry[rows] = ft_calloc(sizeof(t_vector), cols);
	}
	return (arry);
}

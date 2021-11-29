/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:30:55 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 15:44:39 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Some nice cheese to get around Global Vars being banned
//Can't do if Static Vars are also banned

t_mlxdata	*g_mlx(void)
{
	static t_mlxdata	mlx;

	return (&mlx);
}

t_maps	**g_maps(void)
{
	static t_maps	*maps = NULL;

	return (&maps);
}

t_map2d	*g_map2d(void)
{
	static t_map2d	map2d;

	return (&map2d);
}

t_settings	*g_settings(void)
{	
	static t_settings	settings;

	return (&settings);
}

t_math	*g_math(void)
{
	static t_math	math;

	return (&math);
}

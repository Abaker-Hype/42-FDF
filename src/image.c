/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:12:00 by abaker            #+#    #+#             */
/*   Updated: 2021/11/27 19:12:02 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	newimage(int width, int height)
{
	t_image	img;

	img.width = width;
	img.height = height;
	img.img = mlx_new_image(g_mlx()->mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits, &img.linelen, &img.endian);
	return (img);
}

void	colourimage(t_image *img, t_rgb rgb)
{
	t_vector	pos;

	pos.x = 0;
	pos.rgb = rgb;
	while (pos.x < img->width)
	{
		pos.y = 0;
		while (pos.y < img->height)
		{
			setpixel(img, pos);
			pos.y++;
		}
		pos.x++;
	}
}

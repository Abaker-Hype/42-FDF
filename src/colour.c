/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:42:36 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 14:33:18 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setpixel(t_image *img, t_vector v)
{
	char	*addr;

	if (v.x < 0 || v.y < 0 || v.x >= img->width || v.y >= img->height)
		return ;
	addr = img->addr + ((int)v.y * img->linelen + (int)v.x * (img->bits / 8));
	*(unsigned int *)addr = rgb2int(v.rgb);
}

t_rgb	newcolour(char *data)
{
	static char	hex[] = "0123456789abcdef";
	int			n;
	int			i;

	if (!data)
		return (int2rgb(0xFFFFFF));
	data += 3;
	n = 0;
	while (*data)
	{
		i = 0;
		while (i < 16)
		{
			if (*data == hex[i])
			{
				n = n * 16 + i;
				break ;
			}
			i++;
		}
		data++;
	}
	return (int2rgb(n));
}

t_rgb	int2rgb(int colour)
{
	t_rgb	rgb;

	rgb.r = (colour >> 16) & 0xFF;
	rgb.g = (colour >> 8) & 0xFF;
	rgb.b = colour & 0xFF;
	return (rgb);
}

int	rgb2int(t_rgb rgb)
{
	return (rgb.r * 0x10000 + rgb.g * 0x100 + rgb.b);
}

t_rgb	rgbgrad(t_rgb rgb1, t_rgb rgb2, double percent)
{
	t_rgb	grad;

	if (percent == 0)
		return (rgb1);
	if (percent == 1)
		return (rgb2);
	grad.r = rgb1.r * (1 - percent) + rgb2.r * percent;
	grad.g = rgb1.g * (1 - percent) + rgb2.g * percent;
	grad.b = rgb1.b * (1 - percent) + rgb2.b * percent;
	return (grad);
}

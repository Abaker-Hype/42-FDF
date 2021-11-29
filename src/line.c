/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:28:37 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 14:33:14 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct t_linedata {
	double	percent;
	double	slope;
	bool	xaxis;
	int		inc;
}	t_linedata;

static void	update(t_linedata *line, t_vector *pos, t_vector v1, t_vector v2)
{
	if (line->xaxis)
	{
		pos->x += line->inc;
		pos->y = v1.y + (line->slope * (pos->x - v1.x));
		line->percent = fabs(pos->x - v1.x) / fabs(v2.x - v1.x);
	}
	else
	{
		pos->y += line->inc;
		pos->x = v1.x + ((pos->y - v1.y) / line->slope);
		line->percent = fabs(pos->y - v1.y) / fabs(v2.y - v1.y);
	}
	pos->rgb = rgbgrad(v1.rgb, v2.rgb, line->percent);
}

static bool	chkline(t_image *img, t_vector v1, t_vector v2)
{
	return ((v1.x < 0 && v2.x < 0) || (v1.y < 0 && v2.y < 0)
		|| (v1.x >= img->width && v2.x >= img->width)
		|| (v1.y >= img->height && v2.y >= img->height));
}

void	drawline(t_image *img, t_vector v1, t_vector v2)
{
	t_linedata	line;
	t_vector	pos;

	if (chkline(img, v1, v2))
		return ;
	pos = v1;
	line.percent = 0.0;
	line.slope = (v2.y - v1.y) / (v2.x - v1.x);
	line.xaxis = fabs(v1.x - v2.x) >= fabs(v1.y - v2.y);
	line.inc = 1;
	if ((line.xaxis && v2.x < v1.x) || (!line.xaxis && v2.y < v1.y))
		line.inc = -1;
	while (line.percent <= 1.0)
	{
		setpixel(img, pos);
		update(&line, &pos, v1, v2);
	}
}

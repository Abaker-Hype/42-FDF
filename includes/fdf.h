/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:31:07 by abaker            #+#    #+#             */
/*   Updated: 2021/11/26 15:44:41 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <math.h>
# include <stdbool.h>

//Window Size Defines
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_NAME "FDF"
# define SETTINGS_WIDTH 260

//Keycode Defines
# define XK_ECSAPE 53
# define XK_A 0
# define XK_S 1
# define XK_D 2
# define XK_W 13
# define XK_R 15
# define XK_Z 6
# define XK_X 7
# define XK_PLUS 24
# define XK_MINUS 27
# define XK_NUMPLUS 69
# define XK_NUMMINUS 78
# define XK_LEFT 123
# define XK_RIGHT 124
# define XK_DOWN 125
# define XK_UP 126 

typedef struct t_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct t_vector {
	double	x;
	double	y;
	double	z;
	t_rgb	rgb;
}	t_vector;

typedef struct t_image {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits;
	int		linelen;
	int		endian;
}	t_image;

typedef struct t_map2d {
	t_image		panel;
	int			width;
	int			height;
	t_vector	**points;
}	t_map2d;

typedef struct t_math {
	double	sinx;
	double	siny;
	double	cosx;
	double	cosy;
}	t_math;

typedef struct t_mlxdata {
	void	*mlx;
	void	*win;
}	t_mlxdata;

typedef struct t_maps {
	char			*file;
	int				width;
	int				height;
	int				zmax;
	int				zmin;
	t_vector		**points;
	struct t_maps	*prev;
	struct t_maps	*next;
}	t_maps;

typedef struct t_settings {
	t_image		panel;
	double		rotx;
	double		roty;
	double		scale;
	double		offsetx;
	double		offsety;
	int			totalmaps;
	int			currmap;
	t_vector	(*func)();
}	t_settings;

//Totally not using Global Vars ;)
t_mlxdata	*g_mlx(void);
t_maps		**g_maps(void);
t_map2d		*g_map2d(void);
t_math		*g_math(void);
t_settings	*g_settings(void);

bool		initmaps(int n, char **maps);
bool		parsemap(t_maps *map, char *file);

void		defaultsettings(void);
void		updaterot(int key);
void		updateoffset(int key);
void		updatescale(int key);
void		updatemath(void);
void		changemap(int key);
void		destroy(void);
int			closewin(void);

void		loadmap2d(void);
void		loadhooks(void);
void		freehooks(void);

t_image		newimage(int width, int height);
void		colourimage(t_image *img, t_rgb rgb);

t_vector	newvector(int x, int y, char *data);
t_vector	**vectorarray(int rows, int cols);

void		drawsettings(void);
void		render2dmap(void);
void		drawline(t_image *img, t_vector v1, t_vector v2);

t_vector	parallel(t_vector v);

void		setpixel(t_image *img, t_vector v);
t_rgb		newcolour(char *data);
t_rgb		int2rgb(int colour);
int			rgb2int(t_rgb rgb);
t_rgb		rgbgrad(t_rgb rgb1, t_rgb rgb2, double percent);
#endif

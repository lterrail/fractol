/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:21:59 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/14 15:07:54 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "libft.h"

# define WIDTH 1200
# define HEIGHT 800

# define SUCCESS		1
# define ERROR			0

# define KEY_QUIT		53
# define MOUSE_ZOOM_IN	69
# define MOUSE_ZOOM_OUT	78
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126

# define MANDELBROT		10000
# define JULIA			20000

//https://randomascii.wordpress.com/2011/08/13/faster-fractals-through-algebra/

typedef struct		s_pt
{
	int				x;
	int				y;
	double			Z0r;
	double			Z0i;
	double			Zr;
	double			Zi;
	double			Zrcalc;
	double			Zicalc;
}					t_pt;

typedef struct		s_color
{
	int		r;
	int		g;
	int		b;
}					t_color;

typedef struct		s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}					t_img;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	double			zoom;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	t_img			*img;
	t_color			*color;
	int				preci;
	int				algo;
}					t_env;

t_img				*ft_new_image(void *mlx, int width, int height);
int					ft_clear_img(t_img *img);
void				draw_pixel(t_img *img, int x, int y, t_color *color);
int					key_event_press(int keycode, t_env *env);
void				ft_draw_mandelbrot(t_env *env, t_pt pt);
void				ft_draw_julia(t_env *env, t_pt pt);
void				ft_init_draw(t_env *env);
void				ft_color(t_env *env, int distance, int x, int y);

#endif

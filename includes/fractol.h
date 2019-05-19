/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:21:59 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 15:10:54 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "libft.h"

# define WIDTH 800
# define HEIGHT 800

# define SUCCESS		1
# define ERROR			0
# define THREADS		4
# define ZOOM			1.1
# define I_MAX			1

# define KEY_QUIT		53
# define MOUSE_ZOOM_IN	4
# define MOUSE_ZOOM_OUT	5
# define KEY_RESET		71
# define KEY_ZOOM_IN	69
# define KEY_ZOOM_OUT	78
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_COLOR1		83
# define KEY_COLOR2		84
# define KEY_COLOR3		85
# define KEY_COLOR4		86
# define KEY_COLOR5		87
# define KEY_COLOR6		88
# define KEY_COLOR7		89
# define KEY_COLOR8		91
# define KEY_COLOR9		92
# define KEY_Q			12
# define KEY_W			13
# define KEY_STOP		1

# define MANDELBROT		10000
# define JULIA			20000
# define BURNINGSHIP	30000

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
	int				i;
}					t_pt;

typedef struct		s_color
{
	int				r;
	int				rr;
	int				g;
	int				gg;
	int				b;
	int				bb;
}					t_color;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	double			Z0rj;
	double			Z0ij;
	double			zoom;
	double			zoomx;
	double			zoomy;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				stop_mouse;
	t_img			*img;
	t_color			color;
	int				i_max;
	int				algo;
	int				id_thread;
	int				flag;
}					t_env;

void				ft_init_draw(t_env *env);
void				draw_pixel(t_img *img, int x, int y, t_color color);

void				ft_init_mandelbrot(t_env *env);
void				ft_init_julia(t_env *env);
void				ft_init_burningship(t_env *env);

void				ft_draw_mandelbrot(t_env *env, t_pt pt);
void				ft_draw_burningship(t_env *env, t_pt pt);
void				ft_draw_julia(t_env *env, t_pt pt);

int					ft_event_julia(int x, int y, t_env *env);
int					ft_event_mouse(int keycode, int x, int y, t_env *env);
int					ft_event_key(int keycode, t_env *env);

int					ft_clear_img(t_img *img);
t_img				*ft_new_image(void *mlx, int width, int height);

void				ft_exit(t_env *env);
void				ft_color(t_env *env, t_pt pt);
void				ft_display_precision(t_env *env);

#endif

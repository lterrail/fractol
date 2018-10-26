/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:21:59 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/26 06:07:49 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "libft.h"

# define WIDTH 2400
# define HEIGHT 1300

# define SUCCESS		1
# define ERROR			0

# define KEY_QUIT		53

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
	t_img			*img;
	t_color			*color;
	char			*name;
}					t_env;

t_img				*ft_new_image(void *mlx, int width, int height);
int					ft_clear_img(t_img *img);
void				draw_pixel(t_img *img, int x, int y, t_color *color);
int					key_event_press(int keycode, t_env *env);

#endif

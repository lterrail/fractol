/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 10:36:57 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/14 16:10:13 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_draw_julia(t_env *env, t_pt pt)
{
	(void)env;
	(void)pt;
}

void		ft_draw_mandelbrot(t_env *env, t_pt pt)
{
	float distance;
	int i;

	while (++pt.x < fabs((env->x1 - env->x2) * env->zoom))
	{
		pt.y = 0;
		while (++pt.y < fabs((env->y1 - env->y2) * env->zoom))
		{
			pt.Z0r = pt.x / env->zoom + env->x1;
			pt.Z0i = pt.y / env->zoom + env->y1;
			pt.Zr = pt.Z0r;
			pt.Zi = pt.Z0i;
			i = -1;
			distance = 0;
			while (distance < 4 && ++i < env->preci)
			{
				pt.Zrcalc = pt.Zr * pt.Zr - pt.Zi * pt.Zi + pt.Z0r;
				pt.Zicalc = 2 * pt.Zr * pt.Zi + pt.Z0i;
				pt.Zr = pt.Zrcalc;
				pt.Zi = pt.Zicalc;
				distance = pt.Zr * pt.Zr + pt.Zi * pt.Zi;
				ft_color(env, distance, pt.x, pt.y);
			}
		}
	}
}

void			ft_init_draw(t_env *env)
{
	t_pt pt;

	pt.x = -1;
	pt.y = -1;
	pt.Z0r = 0;
	pt.Z0i = 0;
	pt.Zr = 0;
	pt.Zi = 0;
	pt.Zrcalc = 0;
	pt.Zicalc = 0;
	if (env->algo == MANDELBROT)
	{
		ft_draw_mandelbrot(env, pt);
	}
	else if (env->algo == JULIA)
		ft_draw_julia(env, pt);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

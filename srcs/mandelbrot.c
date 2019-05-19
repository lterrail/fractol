/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:21:22 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 12:27:29 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_mandelbrot(t_env *env)
{
	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->zoomx = WIDTH / (env->x2 - env->x1);
	env->zoomy = HEIGHT / (env->y2 - env->y1);
}

void		ft_draw_mandelbrot(t_env *env, t_pt pt)
{
	float distance;

	while (++pt.x < (WIDTH / THREADS) * (env->id_thread + 1))
	{
		pt.y = 0;
		while (++pt.y < HEIGHT)
		{
			pt.Z0r = pt.x / env->zoomx + env->x1;
			pt.Z0i = pt.y / env->zoomy + env->y1;
			pt.Zr = pt.Z0r;
			pt.Zi = pt.Z0i;
			pt.i = -1;
			distance = 0;
			while (distance < 4 && ++pt.i < env->i_max)
			{
				pt.Zrcalc = pt.Zr * pt.Zr - pt.Zi * pt.Zi + pt.Z0r;
				pt.Zicalc = 2 * pt.Zr * pt.Zi + pt.Z0i;
				pt.Zr = pt.Zrcalc;
				pt.Zi = pt.Zicalc;
				distance = pt.Zr * pt.Zr + pt.Zi * pt.Zi;
				ft_color(env, pt);
			}
		}
	}
}

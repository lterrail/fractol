/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:21:05 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 15:14:44 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_burningship(t_env *env)
{
	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->zoomx = WIDTH / (env->x2 - env->x1);
	env->zoomy = HEIGHT / (env->y2 - env->y1);
}

void		ft_draw_burningship(t_env *env, t_pt pt)
{
	float distance;

	while (++pt.x < (WIDTH / THREADS) * (env->id_thread + 1))
	{
		pt.y = 0;
		while (++pt.y < HEIGHT)
		{
			pt.zrstart = pt.x / env->zoomx + env->x1;
			pt.zistart = pt.y / env->zoomy + env->y1;
			pt.zr = pt.zrstart;
			pt.zi = pt.zistart;
			pt.i = -1;
			distance = 0;
			while (distance < 4 && ++pt.i < env->i_max)
			{
				pt.zrcalc = fabs(pt.zr * pt.zr) - pt.zi * pt.zi + pt.zrstart;
				pt.zicalc = 2 * fabs(pt.zr * pt.zi) + pt.zistart;
				pt.zr = pt.zrcalc;
				pt.zi = pt.zicalc;
				distance = pt.zr * pt.zr + pt.zi * pt.zi;
				ft_color(env, pt);
			}
		}
	}
}

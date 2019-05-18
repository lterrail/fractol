/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:00:52 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/16 17:30:01 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_color(t_env *env, t_pt pt)
{
	if (pt.i + 1 == env->i_max)
	{
		env->color->r = 0;
		env->color->g = 0;
		env->color->b = 0;
		draw_pixel(env->img, pt.x, pt.y, env->color);
	}
	else if (!env->color->rr && !env->color->bb && !env->color->bb)
	{
		env->color->r = (pt.i + env->Z0rj + env->Z0ij) * 10;
		env->color->g = (pt.i + env->Z0rj + env->Z0ij) * 50;
		env->color->b = (pt.i + env->Z0rj + env->Z0ij) * 60;
		draw_pixel(env->img, pt.x, pt.y, env->color);
	}
	else
	{
		env->color->r = (pt.i + env->Z0rj
			+ env->Z0ij + env->color->rr) * 10;
		env->color->g = (pt.i + env->Z0rj
			+ env->Z0ij + env->color->gg) * 50;
		env->color->b = (pt.i + env->Z0rj
			+ env->Z0ij + env->color->bb) * 60;
		draw_pixel(env->img, pt.x, pt.y, env->color);
	}
}

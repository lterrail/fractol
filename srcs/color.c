/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:00:52 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 14:59:33 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_color(t_env *env, t_pt pt)
{
	if (pt.i + 1 == env->i_max)
	{
		env->color.r = 0;
		env->color.g = 0;
		env->color.b = 0;
		draw_pixel(env->img, pt.x, pt.y, env->color);
	}
	else if (!env->color.rr && !env->color.bb && !env->color.bb)
	{
		env->color.r = pt.i * 255 / env->i_max;
		env->color.g = 0;
		env->color.b = 20;
		draw_pixel(env->img, pt.x, pt.y, env->color);
	}
	else
	{
		env->color.r = (pt.i + env->color.rr) * 60;
		env->color.g = (pt.i + env->color.gg) * 20;
		env->color.b = (pt.i + env->color.bb) * 10;
		draw_pixel(env->img, pt.x, pt.y, env->color);
	}
}

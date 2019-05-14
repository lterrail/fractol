/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:00:52 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/14 14:23:01 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_color(t_env *env, int distance, int x, int y)
{
	if (distance > 4)
	{
		env->color->r = 255;
		env->color->g = 255;
		env->color->b = 255;
		draw_pixel(env->img, x, y, env->color);
	}
	else
	{
		env->color->r = 100;
		env->color->g = 100;
		env->color->b = 100;
		draw_pixel(env->img, x, y, env->color);
	}
}

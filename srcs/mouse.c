/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:05:54 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/16 16:07:14 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		ft_event_mouse(int keycode, int x, int y, t_env *env)
{
	if (keycode == MOUSE_ZOOM_OUT)
	{
		env->zoom /= 1.4;
		env->x1 += x / env->zoomx - env->zoom;
		env->x2 = -env->x1;
		env->y1 += y / env->zoomy - env->zoom;
		env->y2 = -env->y1;
		env->zoomx *= 1.4;
		env->zoomy *= 1.4;
		env->i_max += 4;
	}
	else if (keycode == MOUSE_ZOOM_IN)
	{
		env->zoom *= 1.4;
		env->x1 += x / env->zoomx - env->zoom;
		env->x2 = -env->x1;
		env->y1 += y / env->zoomy - env->zoom;
		env->y2 = -env->y1;
		env->zoomx /= 1.4;
		env->zoomy /= 1.4;
		env->i_max -= 4;
	}
	ft_init_draw(env);
	return (SUCCESS);
}

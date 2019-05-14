/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 06:03:45 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/14 15:08:16 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_event_press(int keycode, t_env *env)
{
	if (keycode == KEY_QUIT)
		exit (0);
	else if (keycode == MOUSE_ZOOM_IN)
	{
		env->preci += 4;
		env->zoom *= 1.4;
	}
	else if (keycode == MOUSE_ZOOM_OUT)
	{
		env->preci -= 4;
		env->zoom /= 1.4;
	}
	else if (keycode == KEY_LEFT)
		env->x1 += 0.1;
	else if (keycode == KEY_RIGHT)
		env->x1 -= 0.1;
	else if (keycode == KEY_UP)
		env->y1 += 0.1;
	else if (keycode == KEY_DOWN)
		env->y1 -= 0.1;
	ft_init_draw(env);
	return (SUCCESS);
}

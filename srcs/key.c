/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 06:03:45 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/16 17:35:07 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_key_zoom(int keycode, t_env *env)
{
	if (keycode == KEY_ZOOM_IN)
	{
		env->i_max += 4;
		env->zoomx *= 1.4;
		env->zoomy *= 1.4;
	}
	else if (keycode == KEY_ZOOM_OUT)
	{
		env->i_max -= 4;
		env->zoomx /= 1.4;
		env->zoomy /= 1.4;
	}
}

static void	ft_key_move(int keycode, t_env *env)
{
	if (keycode == KEY_LEFT)
		env->x1 += 0.1;
	else if (keycode == KEY_RIGHT)
		env->x1 -= 0.1;
	else if (keycode == KEY_UP)
		env->y1 += 0.1;
	else if (keycode == KEY_DOWN)
		env->y1 -= 0.1;
}

static int	ft_key_color2(int keycode, t_env *env)
{
	if (keycode == KEY_COLOR4)
	{
		env->color->rr = 0;
		env->color->gg = 123;
		env->color->bb = 255;
	}
	else if (keycode == KEY_COLOR5)
	{
		env->color->rr = 123;
		env->color->gg = 0;
		env->color->bb = 0;
	}
	else if (keycode == KEY_COLOR6)
	{
		env->color->rr = 255;
		env->color->gg = 255;
		env->color->bb = 0;
	}
	else if (keycode == KEY_COLOR9)
	{
		env->color->rr = 0;
		env->color->gg = 0;
		env->color->bb = 0;
	}
	return (SUCCESS);
}

static int	ft_key_color(int keycode, t_env *env)
{
	if (keycode == KEY_COLOR1)
	{
		env->color->rr = 0;
		env->color->gg = 0;
		env->color->bb = 255;
	}
	else if (keycode == KEY_COLOR2)
	{
		env->color->rr = 255;
		env->color->gg = 0;
		env->color->bb = 0;
	}
	else if (keycode == KEY_COLOR3)
	{
		env->color->rr = 122;
		env->color->gg = 122;
		env->color->bb = 0;
	}
	else if (keycode == KEY_COLOR9)
	{
		env->color->rr = 0;
		env->color->gg = 0;
		env->color->bb = 0;
	}
	return (ft_key_color2(keycode, env));
}

int			ft_event_key(int keycode, t_env *env)
{
	if (keycode == KEY_QUIT)
		exit (0);
	else if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		ft_key_zoom(keycode, env);
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		ft_key_move(keycode, env);
	else if (keycode >= KEY_COLOR1 && keycode <= KEY_COLOR9)
		ft_key_color(keycode, env);
	else if (keycode == KEY_MOUSE_STOP)
		env->stop_mouse = 1;
	else if (keycode == KEY_Q)
		env->i_max++;
	else if (keycode == KEY_W)
		env->i_max--;
	ft_init_draw(env);
	return (SUCCESS);
}

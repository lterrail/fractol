/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 06:03:45 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 15:06:33 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_key_reset(t_env *env)
{
	env->color.r = 255;
	env->color.g = 255;
	env->color.b = 255;
	env->color.rr = 0;
	env->color.gg = 0;
	env->color.bb = 0;
	env->i_max = 20;
	env->zoom = 1;
	env->zoomx = 0;
	env->zoomy = 0;
	env->Z0rj = 0.285;
	env->Z0ij = 0.01;
	env->stop_mouse = 0;
	if (env->algo == MANDELBROT)
		ft_init_mandelbrot(env);
	else if (env->algo == JULIA)
		ft_init_julia(env);
	else if (env->algo == BURNINGSHIP)
		ft_init_burningship(env);
	ft_init_draw(env);
}

static void	ft_key_move(int keycode, t_env *env)
{
	if (keycode == KEY_LEFT)
		env->x1 += ZOOM / 20;
	else if (keycode == KEY_RIGHT)
		env->x1 -= ZOOM / 20;
	else if (keycode == KEY_UP)
		env->y1 += ZOOM / 20;
	else if (keycode == KEY_DOWN)
		env->y1 -= ZOOM / 20;
	ft_init_draw(env);
}

static void	ft_key_color2(int keycode, t_env *env)
{
	if (keycode == KEY_COLOR4)
	{
		env->color.rr = 0;
		env->color.gg = 123;
		env->color.bb = 255;
	}
	else if (keycode == KEY_COLOR5)
	{
		env->color.rr = 123;
		env->color.gg = 0;
		env->color.bb = 0;
	}
	else if (keycode == KEY_COLOR6)
	{
		env->color.rr = 255;
		env->color.gg = 255;
		env->color.bb = 0;
	}
	else if (keycode == KEY_COLOR9)
	{
		env->color.rr = 0;
		env->color.gg = 0;
		env->color.bb = 0;
	}
	ft_init_draw(env);
}

static void	ft_key_color(int keycode, t_env *env)
{
	if (keycode == KEY_COLOR1)
	{
		env->color.rr = 0;
		env->color.gg = 255;
		env->color.bb = 255;
	}
	else if (keycode == KEY_COLOR2)
	{
		env->color.rr = 255;
		env->color.gg = 0;
		env->color.bb = 0;
	}
	else if (keycode == KEY_COLOR3)
	{
		env->color.rr = 122;
		env->color.gg = 122;
		env->color.bb = 0;
	}
	else if (keycode == KEY_COLOR9)
	{
		env->color.rr = 0;
		env->color.gg = 0;
		env->color.bb = 0;
	}
	ft_key_color2(keycode, env);
}

int			ft_event_key(int keycode, t_env *env)
{
	if (keycode == KEY_QUIT)
		ft_exit(env);
	else if (keycode == KEY_RESET)
		ft_key_reset(env);
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		ft_key_move(keycode, env);
	else if (keycode >= KEY_COLOR1 && keycode <= KEY_COLOR9)
		ft_key_color(keycode, env);
	else if (keycode == KEY_STOP)
		env->stop_mouse = 1;
	else if (keycode == KEY_Q)
		env->i_max++;
	else if (keycode == KEY_W)
		env->i_max--;
	if (keycode == KEY_Q || keycode == KEY_W)
		ft_init_draw(env);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 10:36:57 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/18 17:28:35 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		*ft_onethread(void *env)
{
	ft_init_draw(env);
	pthread_exit(NULL);
}

static void		ft_multithread(t_env *env)
{
	int			i;

	i = 0;
	while (i < THREADS)
	{
		pthread_create(&env->thread[i], NULL, ft_onethread, env);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(env->thread[i], NULL);
		i++;
	}
}

void			*ft_init_draw(t_env *env)
{
	t_pt pt;

	pt.i = -1;
	pt.x = -1;
	pt.y = -1;
	pt.Z0r = 0;
	pt.Z0i = 0;
	pt.Zr = 0;
	pt.Zi = 0;
	pt.Zrcalc = 0;
	pt.Zicalc = 0;
	ft_multithread(env);
	if (env->algo == MANDELBROT)
		ft_draw_mandelbrot(env, pt);
	else if (env->algo == JULIA)
		ft_draw_julia(env, pt);
	else if (env->algo == BURNINGSHIP)
		ft_draw_burningship(env, pt);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return (NULL);
}

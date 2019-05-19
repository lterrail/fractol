/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 10:36:57 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 14:53:39 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

static t_pt		init_value_pt(t_env *v)
{
	t_pt	pt;

	pt.i = -1;
	pt.x = -1 + (WIDTH / THREADS) * (v->id_thread);
	pt.y = -1;
	pt.Z0r = 0;
	pt.Z0i = 0;
	pt.Zr = 0;
	pt.Zi = 0;
	pt.Zrcalc = 0;
	pt.Zicalc = 0;
	return (pt);
}

static void		*ft_onethread(void *env)
{
	t_env	*v;
	t_pt	pt;

	v = (t_env *)env;
	pt = init_value_pt(v);
	if (v->algo == MANDELBROT)
		ft_draw_mandelbrot(v, pt);
	else if (v->algo == JULIA)
		ft_draw_julia(v, pt);
	else if (v->algo == BURNINGSHIP)
		ft_draw_burningship(v, pt);
	return (NULL);
}

void			ft_init_draw(t_env *env)
{
	int			i;
	t_env		tab[THREADS];
	pthread_t	thread[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)env, sizeof(t_env));
		tab[i].id_thread = i;
		pthread_create(&thread[i], NULL, ft_onethread, &tab[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	ft_clear_img(env->img);
	ft_display_precision(env);
}

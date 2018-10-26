/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:07:25 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/26 06:07:47 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_env	*init_env(char **av, t_color *color)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	env->color = color;
	env->color->r = 255;
	env->color->g = 255;
	env->color->b = 255;
	env->name = av[1];
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "SALUT");
	return (env);
}

static void		ft_calculate(t_env *env)
{
	env->img = ft_new_image(env->mlx, WIDTH, HEIGHT);
	double zr = 0;
	double zi = 0;
	double cr = -0.0001;
	double ci = 0.64;
	double temp = 0;
	while (zr * zr + zi * zi <= 4)
	{
		temp = zr * zr - zi * zi + cr;
		zi = zr * zi * 2 + ci;
		zr = temp;
		printf("%100f, %100f\n", temp, temp);
		draw_pixel(env->img->img, temp, temp, env->color);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

int				main(int ac, char **av)
{
	(void)ac;
	t_env	*env;
	t_color	*color;

	color = NULL;
	if (!(env = init_env(av, color)))
		return (0);
	ft_calculate(env);
	mlx_hook(env->win, 2, 0, &key_event_press, env);
	mlx_loop(env->mlx);
	return (0);
}

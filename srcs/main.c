/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:07:25 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/18 17:20:38 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_exit(t_env *env)
{
	free(env->color);
	free(env);
	exit(0);
}

static t_env	*init_env(t_color *color)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	env->algo = 0;
	env->color = color;
	env->color->r = 255;
	env->color->g = 255;
	env->color->b = 255;
	env->color->rr = 0;
	env->color->gg = 0;
	env->color->bb = 0;
	env->i_max = 15;
	env->zoom = 1;
	env->zoomx = 0;
	env->zoomy = 0;
	env->Z0rj = 0.285;
	env->Z0ij = 0.01;
	env->stop_mouse = 0;
	env->mlx = mlx_init();
	return (env);
}

static int		ft_parse_cmd(t_env *env, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Usage: ./fractol [mandelbrot/julia/burningship]\n");
		return (ERROR);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
		env->algo = MANDELBROT;
	else if (!ft_strcmp(av[1], "julia"))
		env->algo = JULIA;
	else if (!ft_strcmp(av[1], "burningship"))
		env->algo = BURNINGSHIP;
	else
	{
		ft_putstr("Usage: ./fractol [mandelbrot/julia/burningship]\n");
		return (ERROR);
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, av[1]);
	env->img = ft_new_image(env->mlx, WIDTH, HEIGHT);
	return (SUCCESS);
}

int				main(int ac, char **av)
{
	t_env		*env;
	t_color		*color;

	color = NULL;
	if (!(env = init_env(color)))
		return (0);
	if (!ft_parse_cmd(env, ac, av))
		ft_exit(env);
	ft_init_draw(env);
	mlx_key_hook(env->win, ft_event_key, env);
	mlx_hook(env->win, 6, (1L << 6), ft_event_julia, env);
	mlx_mouse_hook(env->win, ft_event_mouse, env);
	// mlx_loop(env->mlx);
	pthread_exit(NULL);
	return (0);
}

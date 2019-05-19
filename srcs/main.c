/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:07:25 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 14:49:43 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_exit(t_env *env)
{
	if (env->img)
		free(env->img);
	free(env);
	exit(0);
}

static t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->algo = 0;
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
	env->mlx = mlx_init();
	return (env);
}

static int		ft_parse_cmd(t_env *env, char **av)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		ft_init_mandelbrot(env);
		env->algo = MANDELBROT;
	}
	else if (!ft_strcmp(av[1], "julia"))
	{
		ft_init_julia(env);
		env->algo = JULIA;
	}
	else if (!ft_strcmp(av[1], "burningship"))
	{
		ft_init_burningship(env);
		env->algo = BURNINGSHIP;
	}
	else
		return (ERROR);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, av[1]);
	env->img = ft_new_image(env->mlx, WIDTH, HEIGHT);
	return (SUCCESS);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (!(env = init_env()))
		return (ERROR);
	if (ac != 2 || !ft_parse_cmd(env, av))
	{
		ft_putstr("Usage: ./fractol [mandelbrot/julia/burningship]\n");
		ft_exit(env);
	}
	ft_init_draw(env);
	mlx_key_hook(env->win, ft_event_key, env);
	mlx_hook(env->win, 6, (1L << 6), ft_event_julia, env);
	mlx_mouse_hook(env->win, ft_event_mouse, env);
	mlx_loop(env->mlx);
	return (SUCCESS);
}

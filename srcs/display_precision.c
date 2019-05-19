/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:28:57 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/19 14:52:30 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_display_precision(t_env *env)
{
	char	*precision;

	if (!(precision = ft_itoa(env->i_max)))
		ft_exit(env);
	mlx_string_put(env->mlx, env->win, 50, 40, 0xFFFFFF, "precision ");
	mlx_string_put(env->mlx, env->win, 160, 40, 0xFFFFFF, precision);
	free(precision);
}

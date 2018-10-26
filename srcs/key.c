/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 06:03:45 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/26 06:06:13 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_event_press(int keycode, t_env *env)
{
	(void)env;
	if (keycode == KEY_QUIT)
		exit (0);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 05:31:10 by lterrail          #+#    #+#             */
/*   Updated: 2019/05/16 17:50:54 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_img *img, int x, int y, t_color *color)
{
	img->data[(x * (img->bpp / 8)) + (y * img->size_line)] = color->b;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 1] = color->g;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 2] = color->r;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:09:44 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 01:26:17 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_image.h"
#include "mlx_color.h"

int	image_pixel_put(t_image *img, int x, int y, t_color color)
{
	char	*dst;

	if (!img)
		return (1);
	dst = img->addr
			+ (y * img->line_length)
			+ (x * (img->bits_per_pixel / 8));
	*(t_color *)dst = color;
	return (0);
}

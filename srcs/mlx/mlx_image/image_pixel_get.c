/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:52:50 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 00:59:07 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"

unsigned int	image_pixel_get(t_image *image, int x, int y)
{
	char			*dst;
	unsigned int	color;

	if (!image)
		return (1);
	dst = image->addr
			+ (((image->height - 1) - y) * image->line_length)
			+ (x * (image->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

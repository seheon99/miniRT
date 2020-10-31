/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:45:33 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:38:13 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"

int	color_get_t()
{
	return (0);
}

int	color_get_r(t_color color)
{
	return (255.999 * color.e[0]);
}

int	color_get_g(t_color color)
{
	return (255.999 * color.e[1]);
}

int	color_get_b(t_color color)
{
	return (255.999 * color.e[2]);
}

unsigned int
	color_get_trgb(t_color color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = color_get_t() & 0xFF;
	r = color_get_r(color) & 0xFF;
	g = color_get_g(color) & 0xFF;
	b = color_get_b(color) & 0xFF;
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

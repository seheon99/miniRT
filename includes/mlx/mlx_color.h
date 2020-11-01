/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:30:39 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 21:27:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLOR_H
# define MLX_COLOR_H

# include "lib/vec3.h"

typedef	t_vec3	t_color;

/*
**	-----------------------------------
**	color_initialize.c
**	-----------------------------------
*/

t_color			color_create(double r, double g, double b);

/*
**	-----------------------------------
**	color_palette.c
**	-----------------------------------
*/

int				color_get_t();
int				color_get_r(t_color color);
int				color_get_g(t_color color);
int				color_get_b(t_color color);
unsigned int	color_get_trgb(t_color color);

#endif

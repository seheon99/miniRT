/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:48:16 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 04:59:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "mlx/mlx_color.h"

# include "raytracing/point3.h"

struct	s_texture
{
	void	(*del)(void **map);
	t_color	(*value)(double u, double v, const t_point3 p);
	void	*map;
};
typedef	struct s_texture	t_texture;

/*
**	-----------------------------------
**	texture_initialize.c
**	-----------------------------------
*/

void	texture_delete(t_texture **texture);

#endif

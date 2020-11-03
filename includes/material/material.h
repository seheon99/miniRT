/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:09:35 by seyu              #+#    #+#             */
/*   Updated: 2020/11/03 02:32:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "mlx/mlx_color.h"

# include "raytracing/ray.h"
# include "raytracing/record.h"

/*
**	t_ray2	ray
**	ray.ray1 = &(r_in)
**	ray.ray2 = &(scattered)
*/

struct	s_material
{
	void	(*del)(void **condition);
	int		(*scatter)(void *condition, t_hit_record rec,
						t_color *attenuation, t_ray2 ray);
	void	*condition;
};
typedef	struct s_material	t_material;

/*
**	-----------------------------------
**	material_initialize.c
**	-----------------------------------
*/

void	material_delete(t_material **mat);

#endif

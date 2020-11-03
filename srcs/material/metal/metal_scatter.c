/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal_scatter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:23:35 by seyu              #+#    #+#             */
/*   Updated: 2020/11/03 03:10:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"

#include "raytracing/record.h"
#include "raytracing/ray.h"

#include "material/material.h"
#include "material/metal.h"

/*
**	t_ray2	ray
**	*(ray.ray1) = r_in
**	*(ray.ray2) = scattered
*/

int	metal_scatter(void *metal, t_hit_record rec,
				t_color *attenuation, t_ray2 ray)
{
	t_vec3	reflected;

	reflected = vec3_reflect(vec3_unit_vector(ray_direction(*(ray.ray1))),
								rec.normal);
	*(ray.ray2) = ray_create(rec.p, reflected);
	*attenuation = ((t_metal *)(metal))->albedo;
	return (vec3_dot(ray_direction(*(ray.ray2)), rec.normal) > 0);
}

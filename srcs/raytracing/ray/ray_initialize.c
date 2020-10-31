/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:37:54 by seyu              #+#    #+#             */
/*   Updated: 2020/10/29 04:39:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

t_ray		ray_create(t_point3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.orig = origin;
	ray.dir = direction;
	return (ray);
}

t_point3	ray_origin(t_ray ray)
{
	return (ray.orig);
}

t_vec3		ray_direction(t_ray ray)
{
	return (ray.dir);
}

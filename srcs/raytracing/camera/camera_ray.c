/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:03:10 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 01:35:15 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/vec3.h"

#include "raytracing/ray.h"
#include "raytracing/camera.h"

t_ray	camera_get_ray(t_camera cam, double u, double v)
{
	t_ray	ray;

	ray = ray_create(cam.origin,
			vec3_sub(
				vec3_add(
					vec3_add(
						cam.lower_left_corner,
						vec3_mul2(
							cam.horizontal,
							u)),
					vec3_mul2(
						cam.vertical,
						v)),
				cam.origin));
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:56:25 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 01:09:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raytracing/camera.h"

#include "utils.h"

t_camera	camera_create(t_point3 lookfrom, t_point3 lookat, t_vec3 vup,
							double vfov, double aspect_ratio)
{
	t_camera	cam;
	double		theta;
	double		viewport_height;
	double		viewport_width;

	t_vec3		w = vec3_unit_vector(vec3_sub(lookfrom, lookat));
	t_vec3		u = vec3_unit_vector(vec3_cross(vup, w));
	t_vec3		v = vec3_cross(w, u);

	theta = degrees_to_radians(vfov);
	viewport_height = 2.0 * tan(theta / 2);
	viewport_width = aspect_ratio * viewport_height;
	cam.origin = lookfrom;
	cam.horizontal = vec3_mul2(u, viewport_width);
	cam.vertical = vec3_mul2(v, viewport_height);
	cam.lower_left_corner =
		vec3_sub(
			vec3_sub(
				vec3_sub(
					cam.origin,
					vec3_div2(cam.horizontal, 2)),
				vec3_div2(cam.vertical, 2)),
			w);
	return (cam);
}

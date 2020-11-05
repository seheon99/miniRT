/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:56:25 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 00:13:24 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raytracing/camera.h"

#include "utils.h"

t_camera	camera_create(double vfov, double aspect_ratio)
{
	t_camera	cam;
	double		theta;
	double		viewport_height;
	double		viewport_width;
	double		focal_length;

	theta = degrees_to_radians(vfov);
	viewport_height = 2.0 * tan(theta / 2);
	viewport_width = aspect_ratio * viewport_height;
	focal_length = 1;
	cam.origin = point3_create(0, 0, 0);
	cam.horizontal = vec3_create(viewport_width, 0, 0);
	cam.vertical = vec3_create(0, viewport_height, 0);
	cam.lower_left_corner =
		vec3_sub(
			vec3_sub(
				vec3_sub(
					cam.origin,
					vec3_div2(cam.horizontal, 2)),
				vec3_div2(cam.vertical, 2)),
			vec3_create(0, 0, focal_length));
	return (cam);
}

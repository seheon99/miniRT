/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:56:25 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 01:52:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing/camera.h"

t_camera	camera_create(int width, int height)
{
	t_camera	cam;
	double		aspect_ratio;
	double		viewport_height;
	double		viewport_width;
	double		focal_length;

	aspect_ratio = (double)width / height;
	viewport_height = 2;
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

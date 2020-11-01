/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:49:43 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 01:46:22 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "libs/vec3.h"

# include "raytracing/point3.h"
# include "raytracing/ray.h"

struct	s_camera
{
	t_point3	origin;
	t_point3	lower_left_corner;
	t_vec3		horizontal;
	t_vec3		vertical;
};
typedef	struct s_camera	t_camera;

/*
**	-----------------------------------
**	camera_initialize.c
**	-----------------------------------
*/

t_camera	camera_create(int width, int height);

/*
**	-----------------------------------
**	camera_ray.c
**	-----------------------------------
*/

t_ray		camera_get_ray(t_camera cam, double u, double v);

#endif

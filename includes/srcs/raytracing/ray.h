/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:32:02 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 14:40:26 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"
# include "point3.h"

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};
typedef	struct s_ray	t_ray;

/*
**	-----------------------------------
**	ray_initialize.c
**	-----------------------------------
*/

t_ray		ray_create(t_point3 origin, t_vec3 direction);
t_point3	ray_origin(t_ray ray);
t_vec3		ray_direction(t_ray ray);

/*
**	-----------------------------------
**	ray_utils.c
**	-----------------------------------
*/

t_point3	ray_at(t_ray ray, double t);

#endif

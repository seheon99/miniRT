/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:40:14 by seyu              #+#    #+#             */
/*   Updated: 2020/10/29 04:54:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

t_point3	ray_at(t_ray ray, double t)
{
	return (vec3_add(ray_origin(ray), vec3_mul2(ray_direction(ray), t)));
}

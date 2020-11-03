/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:27:41 by seyu              #+#    #+#             */
/*   Updated: 2020/11/03 02:14:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"

t_vec3	vec3_unit_vector(const t_vec3 v)
{
	return (vec3_div2(v, vec3_length(v)));
}

double	vec3_length(const t_vec3 v)
{
	return (sqrt(vec3_length_squared(v)));
}

double	vec3_length_squared(const t_vec3 v)
{
	return ((v.e[0] * v.e[0])
			+ (v.e[1] * v.e[1])
			+ (v.e[2] * v.e[2]));
}

int		vec3_is_near_zero(const t_vec3 v)
{
	double	s;
	double	e[3];

	s = 1e-8;
	e[0] = (v.e[0] > 0 ? v.e[0] : -v.e[0]);
	e[1] = (v.e[1] > 0 ? v.e[1] : -v.e[1]);
	e[2] = (v.e[2] > 0 ? v.e[2] : -v.e[2]);
	return ((e[0] < s) && (e[1] < s) && (e[2] < s));
}

t_vec3	vec3_reflect(const t_vec3 v, const t_vec3 n)
{
	return (vec3_sub(v, vec3_mul2(
				vec3_mul2(n, vec3_dot(v, n)), 2)));
}

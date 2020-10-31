/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:27:41 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:41:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libs/vec3.h"

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

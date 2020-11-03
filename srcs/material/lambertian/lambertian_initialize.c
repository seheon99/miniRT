/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian_initialize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:10:23 by seyu              #+#    #+#             */
/*   Updated: 2020/11/03 03:11:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"

#include "material/material.h"
#include "material/lambertian.h"

t_material	*lambertian_new(t_color a)
{
	t_material	*mat;

	mat = (t_material *)malloc(sizeof(t_material));
	mat->del = lambertian_delete;
	mat->scatter = lambertian_scatter;
	mat->condition = (t_lambertian *)malloc(sizeof(t_lambertian));
	((t_lambertian *)(mat->condition))->albedo = a;
	return (mat);
}

void		lambertian_delete(void **condition)
{
	free(*condition);
	*condition = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:32:57 by seyu              #+#    #+#             */
/*   Updated: 2020/11/01 21:26:46 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "raytracing/point3.h"

#include "element/hittable.h"
#include "element/sphere.h"

t_hittable	*sphere_new(t_point3 center, double radius)
{
	t_hittable	*object;

	object = (t_hittable *)malloc(sizeof(t_hittable));
	object->del = sphere_delete;
	object->hit = sphere_hit;
	object->element = (void *)malloc(sizeof(t_sphere));
	((t_sphere *)(object->element))->center = center;
	((t_sphere *)(object->element))->radius = radius;
	return (object);
}

/*
**	sphere_delete()
**
**	This function
**		FREE the element of t_hittable,
**		NOT FREE the t_hittable structure.
**	The t_hittable structure will be free in hittable_list_clear() function.
**
**	@param	void	*obj:	t_hittable struct that have element to free
**	@return	void
*/

void		sphere_delete(void *obj)
{
	t_hittable	*object;

	object = obj;
	free(object->element);
	object->element = NULL;
}

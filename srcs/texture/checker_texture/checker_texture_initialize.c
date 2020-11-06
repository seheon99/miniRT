/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture_initialize.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:09:35 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 14:23:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"

#include "texture/texture.h"
#include "texture/solid_color.h"
#include "texture/checker_texture.h"

t_texture	*checker_texture_new(t_texture *o, t_texture *e)
{
	t_texture			*check;
	t_checker_texture	*map;

	check = (t_texture *)malloc(sizeof(t_texture));
	check->del = checker_texture_delete;
	check->value = checker_texture_value;
	map = (t_checker_texture *)malloc(sizeof(t_checker_texture));
	map->odd = o;
	map->even = e;
	check->map = map;
	return (check);
}

t_texture	*checker_texture_new_color(t_color o, t_color e)
{
	t_texture	*odd;
	t_texture	*even;

	odd = solid_color_new(o);
	even = solid_color_new(e);
	return (checker_texture_new(odd, even));
}

void		checker_texture_delete(void **map)
{
	t_checker_texture	*check;

	check = *map;
	check->odd->del((void **)(&(check->odd)));
	check->even->del((void **)(&(check->even)));
	free(check);
	*map = NULL;
}

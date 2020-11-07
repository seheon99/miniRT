/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:17:32 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 16:48:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "material/material.h"

#include "error.h"

void	material_delete(t_material **mat)
{
	((*mat)->del)((*mat)->condition);
	(*mat)->condition = NULL;
	free(*mat);
	*mat = NULL;
}

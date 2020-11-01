/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:36:22 by seyu              #+#    #+#             */
/*   Updated: 2020/11/01 19:37:30 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "element/hittable.h"

void	hittable_common_del(void *object)
{
	free(object);
}

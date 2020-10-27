/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_new_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:24:22 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 01:29:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_window.h"
#include "mlx_image.h"

t_image	*window_new_image(t_window *win, int width, int height)
{
	t_image	*imgptr;

	imgptr = window_find_last_image(win);
	imgptr->next_img = (t_image *)malloc(sizeof(t_image));
	imgptr = imgptr->next_img;
	imgptr->mlx_img = mlx_new_image(win->mlx, width, height);
	imgptr->addr = mlx_get_data_addr(imgptr->mlx_img,
										&(imgptr->bits_per_pixel),
										&(imgptr->line_length),
										&(imgptr->endian));
	imgptr->next_img = NULL;
	return (imgptr);
}

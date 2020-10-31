/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_new_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:24:22 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:46:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

t_image	*window_new_image(t_window *win, int width, int height)
{
	t_image	*imgptr;

	imgptr = window_find_last_image(win);
	if (!imgptr)
	{
		imgptr = (t_image *)malloc(sizeof(t_image));
		win->imglst_head = imgptr;
	}
	else
	{
		imgptr->next_img = (t_image *)malloc(sizeof(t_image));
		imgptr = imgptr->next_img;
	}
	imgptr->mlx_img = mlx_new_image(win->mlx, width, height);
	imgptr->addr = mlx_get_data_addr(imgptr->mlx_img,
										&(imgptr->bits_per_pixel),
										&(imgptr->line_length),
										&(imgptr->endian));
	imgptr->width = width;
	imgptr->height = height;
	imgptr->next_img = NULL;
	return (imgptr);
}

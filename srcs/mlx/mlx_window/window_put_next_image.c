/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_put_next_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:29:07 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 16:44:38 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libs/mlx.h"

#include "mlx/mlx_window.h"
#include "mlx/mlx_image.h"

int	window_put_next_image(t_window *win)
{
	if (!win)
	{
		perror("Null %s pointer was passed on to the window_put_next_image()");
		exit(1);
	}
	if (win->current_imgptr && win->current_imgptr->next_img)
		win->current_imgptr = win->current_imgptr->next_img;
	else
		win->current_imgptr = win->imglst_head;
	return (window_put_image(win, win->current_imgptr, 0, 0));
}

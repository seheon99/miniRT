/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_delete_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:52:42 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:45:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

/*
**	window_delete_image
**
**	Connect previous image to next image,
**		and then delete and free img from win
**
**	@param	t_window	*win	win contains img
**	@param	t_image		*img	img will be deleted
**	@return	int			0		img was deleted by the mlx function
**						1		img does not exist in the win pointer
*/

int	window_delete_image(t_window *win, t_image *img)
{
	t_image	*win_img;
	t_image	*prev_img;

	if (!(win_img = window_find_image(win, img)))
		return (1);
	if (!(prev_img = window_find_prev_image(win, img)))
		win->imglst_head = win_img->next_img;
	else
		prev_img->next_img = win_img->next_img;
	mlx_destroy_image(win->mlx, win_img->mlx_img);
	free(win_img);
	return (0);
}

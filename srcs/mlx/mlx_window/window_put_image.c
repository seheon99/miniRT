/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_put_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:37:03 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 00:45:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"
#include "mlx_image.h"

/*
**	window_put_image
**
**	After check if t_image is in t_window,
**		put t_image on t_window.
**
**	@param	t_window	*win	t_window where t_image will be putted
**	@param	t_image		*img	t_image to be putted on t_window
**	@return	int			0		Success to putting t_image on t_window
**						1		There is no t_image in t_window
*/

int	window_put_image(t_window *win, t_image *img, int x, int y)
{
	t_image	*win_img;

	win_img = window_find_image(win, img);
	if (!win_img)
		return (1);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win_img->mlx_img, x, y);
	return (0);
}

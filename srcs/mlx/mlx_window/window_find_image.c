/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_find_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:30:21 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 01:28:36 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"
#include "mlx_image.h"

t_image	*window_find_image(t_window *win, t_image *img)
{
	t_image	**win_img;

	win_img = win->imglst_head;
	while (*win_img && *win_img != img)
		(*win_img) = (*win_img)->next_img;
	return (*win_img);
}

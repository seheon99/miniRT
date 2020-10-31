/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_find_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:30:21 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:45:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

t_image	*window_find_image(t_window *win, t_image *img)
{
	t_image	*win_img;

	win_img = win->imglst_head;
	while (win_img && win_img != img)
		(win_img) = (win_img)->next_img;
	return (win_img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_delete_image_all.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:31:21 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:45:16 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

int	window_delete_image_all(t_window *win)
{
	while (win->imglst_head)
		window_delete_image(win, win->imglst_head);
	return (0);
}

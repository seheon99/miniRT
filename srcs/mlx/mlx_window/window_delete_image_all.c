/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_delete_image_all.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:31:21 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 00:33:41 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"
#include "mlx_image.h"

int	window_delete_image_all(t_window *win)
{
	while (win->imglst_head)
		window_delete_image(win, *(win->imglst_head));
	return (0);
}

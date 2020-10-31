/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_find_last_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:27:46 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:45:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

t_image	*window_find_last_image(t_window *win)
{
	t_image	*imgptr;

	imgptr = win->imglst_head;
	while (imgptr && imgptr->next_img)
		imgptr = imgptr->next_img;
	return (imgptr);
}

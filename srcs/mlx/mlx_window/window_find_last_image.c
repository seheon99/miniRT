/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_find_last_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:27:46 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 00:14:36 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"
#include "mlx_image.h"

t_image	*window_find_last_image(t_window *win)
{
	t_image	**imgptr;

	imgptr = win->imglst_head;
	while (*(imgptr) && (*imgptr)->next_img)
		*imgptr = (*imgptr)->next_img;
	return (*imgptr);
}

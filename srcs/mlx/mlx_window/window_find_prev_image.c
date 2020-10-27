/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_find_prev_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:23:24 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 00:26:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"
#include "mlx_image.h"

t_image	*window_find_prev_image(t_window *win, t_image *img)
{
	t_image	**imgptr;

	imgptr = win->imglst_head;
	if (!imgptr || *imgptr == img)
		return (NULL);
	while ((*imgptr)->next_img != img)
		(*imgptr) = (*imgptr)->next_img;
	return (*imgptr);
}

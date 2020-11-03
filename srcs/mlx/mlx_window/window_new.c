/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:06:08 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 16:31:14 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx_window.h"

t_window	*window_new(int size_x, int size_y, char *title)
{
	t_window	*win;

	win = (t_window *)malloc(sizeof(t_window));
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, size_x, size_y, title);
	win->imglst_head = NULL;
	win->current_imgptr = NULL;
	return (win);
}

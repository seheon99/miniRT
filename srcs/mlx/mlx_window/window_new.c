/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:06:08 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 04:13:44 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libs/mlx.h"
#include "mlx/mlx_window.h"

t_window	*window_new(int size_x, int size_y, char *title)
{
	t_window	*win;
	int			screen_x;
	int			screen_y;

	win = (t_window *)malloc(sizeof(t_window));
	win->mlx = mlx_init();
	mlx_get_screen_size(win->mlx, &screen_x, &screen_y);
	size_x = size_x < screen_x ? size_x : screen_x;
	size_y = size_y < screen_y ? size_y : screen_y;
	win->mlx_win = mlx_new_window(win->mlx, size_x, size_y, title);
	win->imglst_head = NULL;
	win->current_imgptr = NULL;
	return (win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:56:20 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 19:51:54 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include <stddef.h>

# include "libs/mlx.h"
# include "mlx/mlx_image.h"
# include "mlx/mlx_define.h"

struct		s_window
{
	void	*mlx;
	void	*mlx_win;
	t_image	*imglst_head;
	t_image	*current_imgptr;
};
typedef	struct s_window	t_window;

/*
**	-----------------------------------
**	Window Initialization Functions
**	-----------------------------------
*/

t_window	*window_new(int size_x, int size_y, char *title);
int			window_delete(t_window **win);
int			window_clear(t_window *win);

/*
**	-----------------------------------
**	Image Initialization Functions
**	-----------------------------------
*/

t_image		*window_new_image(t_window *win, int width, int height);
int			window_delete_image(t_window *win, t_image *img);
int			window_put_image(t_window *win, t_image *img, int x, int y);
int			window_put_next_image(t_window *win);

/*
**	-----------------------------------
**	Image List Functions
**	-----------------------------------
*/

t_image		*window_find_last_image(t_window *win);
t_image		*window_find_prev_image(t_window *win, t_image *img);
t_image		*window_find_image(t_window *win, t_image *img);
int			window_delete_image_all(t_window *win);

/*
**	-----------------------------------
**	window_eventhook.c
**	-----------------------------------
*/

int			window_keypress(int keycode, t_window **win);

#endif

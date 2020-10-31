/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:09:54 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:44:12 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_window.h"

int	window_clear(t_window *win)
{
	return (mlx_clear_window(win->mlx, win->mlx_win));
}

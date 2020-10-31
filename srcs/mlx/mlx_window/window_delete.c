/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:13:35 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:44:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx_window.h"

int	window_delete(t_window **win)
{
	int		rtn;

	window_delete_image_all(*win);
	rtn = mlx_destroy_window((*win)->mlx, (*win)->mlx_win);
	free(*win);
	*win = NULL;
	return (rtn);
}

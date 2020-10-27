/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:21:45 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 02:18:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	-----------------------------------
**	Library Headerfiles
**	-----------------------------------
*/

#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"

/*
**	-----------------------------------
**	Sources Headerfiles
**	-----------------------------------
*/

#include "mlx_window.h"
#include "mlx_image.h"
#include "mlx_color.h"

#include "error.h"

/*
**	-----------------------------------
**	main function
**	-----------------------------------
*/

int	main(int argc, char **argv)
{
	t_window	*window;
	t_image		*image;

	if (argc == 1)
	{
		error_usage(argv[0]);
	}
	window = window_new(960, 540, "Hello, World!");
	window_new_image(window, 960, 540);
	image = window_find_last_image(window);
	image_pixel_put(image, 480, 270, 0x00FF0000);
	window_put_image(window, image, 0, 0);
	mlx_loop(window->mlx);
}

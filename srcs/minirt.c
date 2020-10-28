/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:21:45 by seyu              #+#    #+#             */
/*   Updated: 2020/10/29 00:16:43 by seyu             ###   ########.fr       */
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
**	main functions
**	-----------------------------------
*/

static void
	make_my_first_image(t_image *img, int image_width, int image_height)
{
	int	x;
	int	y;
	int	r;
	int	g;
	int	b;

	y = 0;
	while (y < image_height)
	{
		x = 0;
		while (x < image_width)
		{
			r = (double)x / (image_width - 1) * 255.999;
			g = (double)y / (image_height - 1) * 255.999;
			b = 255.999 / 4;
			image_pixel_put(img, x, y, color_create_trgb(128, r, g, b));
			x += 1;
		}
		y += 1;
	}
}

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
	window_put_image(window, image, 0, 0);
	make_my_first_image(image, 960, 540);
	mlx_loop(window->mlx);
}

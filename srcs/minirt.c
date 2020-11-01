/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:21:45 by seyu              #+#    #+#             */
/*   Updated: 2020/11/01 20:49:12 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	-----------------------------------
**	Library Headerfiles
**	-----------------------------------
*/

#include "lib/mlx.h"
#include "lib/libft.h"
#include "lib/ft_printf.h"
#include "lib/vec3.h"

/*
**	-----------------------------------
**	Sources Headerfiles
**	-----------------------------------
*/

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

#include "raytracing/ray.h"
#include "raytracing/record.h"

#include "element/hittable.h"
#include "element/hittable_list.h"
#include "element/sphere.h"

#include "error.h"

/*
**	-----------------------------------
**	Ray Functions
**	-----------------------------------
*/

static t_color
	ray_color(const t_ray r, t_hittable_list *world)
{
	t_hit_record	rec;
	t_vec3			unit_direction;
	double			t;

	if (hittable_list_hit(world, r, range_create(0, INFINITY), &rec))
	{
		return (vec3_mul2(vec3_add(rec.normal, color_create(1, 1, 1)), 0.5));
	}
	unit_direction = vec3_unit_vector(ray_direction(r));
	t = 0.5 * (vec3_y(unit_direction) + 1.0);
	return (vec3_add(
		vec3_mul2(color_create(1, 1, 1), (1.0 - t)),
		vec3_mul2(color_create(0.5, 0.7, 1.0), t)
	));
}

/*
**	-----------------------------------
**	Main Functions
**	-----------------------------------
*/

static void
	make_my_image(t_image *img, int image_width, int image_height)
{
	int		x;
	int		y;

	t_hittable_list	world;

	double	viewport_height = 2.0;
	double	viewport_width =
				((double)image_width / image_height) * viewport_height;
	double	focal_length = 1.0;

	t_vec3	origin = vec3_create(0, 0, 0);
	t_vec3	horizontal = vec3_create(viewport_width, 0, 0);
	t_vec3	vertical = vec3_create(0, viewport_height, 0);
	t_vec3	lower_left_corner =
				vec3_sub(
					vec3_sub(
						vec3_sub(
							origin,
							vec3_div2(horizontal, 2)
						),
						vec3_div2(vertical, 2)
					),
					vec3_create(0, 0, focal_length)
				);

	t_ray	r;
	double	u;
	double	v;
	t_color	pixel_color;

	hittable_list_add(&world, sphere_new(point3_create(0, 0, -1), 1));
	//hittable_list_add(&world, sphere_new(point3_create(0, -100.5, -1), 100));

	y = 0;
	while (y < image_height)
	{
		ft_printf("\rScanlines remaining: %d ", y);
		x = 0;
		while (x < image_width)
		{
			u = (double)x / (image_width - 1);
			v = (double)y / (image_height - 1);
			r = ray_create(
					origin,
					vec3_sub(
						vec3_add(
							vec3_add(
								lower_left_corner,
								vec3_mul2(horizontal, u)
							),
							vec3_mul2(vertical, v)
						),
						origin
					)
				);
			pixel_color = ray_color(r, &world);
			image_pixel_put(img, x, y, pixel_color);
			x += 1;
		}
		y += 1;
	}
	ft_printf("\nDone.\n");
}

int	main(int argc, char **argv)
{
	t_window	*window;
	t_image		*image;

	if (argc != 1)
		error_usage(argv[0]);
	window = window_new(960, 540, "Hello, World!");
	window_new_image(window, 960, 540);
	image = window_find_last_image(window);
	make_my_image(image, 960, 540);
	window_put_image(window, image, 0, 0);
	mlx_loop(window->mlx);
}

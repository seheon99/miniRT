/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:21:45 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:43:41 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	-----------------------------------
**	Library Headerfiles
**	-----------------------------------
*/

#include "libs/mlx.h"
#include "libs/libft.h"
#include "libs/ft_printf.h"
#include "libs/vec3.h"

/*
**	-----------------------------------
**	Sources Headerfiles
**	-----------------------------------
*/

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

#include "raytracing/ray.h"

#include "error.h"

/*
**	-----------------------------------
**	Ray Functions
**	-----------------------------------
*/

static double
	ray_hit_sphere(const t_point3 center, double radius, const t_ray r)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec3_sub(ray_origin(r), center);
	a = vec3_dot(ray_direction(r), ray_direction(r));
	b = 2.0 * vec3_dot(oc, ray_direction(r));
	c = vec3_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

static t_color
	ray_color(t_ray r)
{
	t_vec3	unit_direction;
	t_vec3	n;
	double	t;

	t = ray_hit_sphere(point3_create(0, 0, -1), 0.5, r);
	if (t > 0)
	{
		n = vec3_unit_vector(
					vec3_sub(
						ray_at(r, t),
						vec3_create(0, 0, -1)
					));
		return (vec3_mul2(
					color_create(vec3_x(n) + 1, vec3_y(n) + 1, vec3_z(n) + 1),
					0.5
				));
	}
	unit_direction = vec3_unit_vector(ray_direction(r));
	t = 0.5 * (vec3_y(unit_direction) + 1.0);
	return (vec3_add(
				vec3_mul2(
					color_create(1.0, 1.0, 1.0),
					1.0 - t
				),
				vec3_mul2(
					color_create(0.5, 0.7, 1.0),
					t
				)));
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
			pixel_color = ray_color(r);
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

	if (argc == 1)
	{
		error_usage(argv[0]);
	}
	window = window_new(960, 540, "Hello, World!");
	window_new_image(window, 960, 540);
	image = window_find_last_image(window);
	make_my_image(image, 960, 540);
	window_put_image(window, image, 0, 0);
	mlx_loop(window->mlx);
}

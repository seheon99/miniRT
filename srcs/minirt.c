/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:21:45 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 19:42:58 by seyu             ###   ########.fr       */
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
#include "raytracing/record.h"
#include "raytracing/camera.h"

#include "element/hittable.h"
#include "element/hittable_list.h"
#include "element/sphere.h"

#include "material/material.h"
#include "material/lambertian.h"
#include "material/metal.h"
#include "material/dielectric.h"

#include "error.h"
#include "utils.h"

/*
**	-----------------------------------
**	Ray Functions
**	-----------------------------------
*/

static t_color
	ray_color(t_ray r, t_hittable_list *world, int depth)
{
	t_hit_record	rec;
	t_vec3			unit_direction;
	double			t;

	if (depth <= 0)
		return (color_create(0, 0, 0));
	if (hittable_list_hit(world, r, range_create(0.001, INFINITY), &rec))
	{
		t_ray	scattered;
		t_color	attenuation;

		if (rec.mat_ptr->scatter(rec.mat_ptr->condition,
					rec, &attenuation, ray2_create(&r, &scattered)))
			return (vec3_mul(attenuation,
					ray_color(scattered, world, depth - 1)));
		return (color_create(0, 0, 0));
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
	int		samples;

	t_ray	r;
	t_color	pixel_color;

	t_camera	cam;

	t_hittable_list	*world;

	cam = camera_create(image_width, image_height);

	t_material	*material_ground = lambertian_new(color_create(0.8, 0.8, 0));
	t_material	*material_center = lambertian_new(color_create(0.1, 0.2, 0.5));
	t_material	*material_left = dielectric_new(1.5);
	t_material	*material_right = metal_new(color_create(0.8, 0.6, 0.2), 0.0);

	world = hittable_list_new(sphere_new(point3_create(0, 0, -1), 0.5, material_center));
	hittable_list_add(world, sphere_new(point3_create(0, -100.5, -1), 100, material_ground));
	hittable_list_add(world, sphere_new(point3_create(-1, 0, -1), 0.5, material_left));
	hittable_list_add(world, sphere_new(point3_create(1, 0, -1), 0.5, material_right));

	y = -1;
	while (++y < image_height)
	{
		ft_printf("\rScanlines remaining: %d%% ", y * 100 / image_height);
		x = -1;
		while (++x < image_width)
		{
			pixel_color = color_create(0, 0, 0);
			samples = -1;
			while (++samples < SAMPLES_PER_PIXEL)
			{
				r = camera_get_ray(cam,
					((double)x + random_double(0, 1)) / (image_width - 1),
					((double)y + random_double(0, 1)) / (image_height - 1));
				pixel_color = vec3_add(pixel_color,
						ray_color(r, world, MAX_DEPTH));
			}
			image_pixel_put(img, x, y, pixel_color);
		}
	}
	hittable_list_delete(&world);
	ft_printf("\rScanlines remaining: %d%% ", 100);
	ft_printf("\nDone.\n");
}

static void
	hook(t_window **win)
{
	mlx_hook((*win)->mlx_win, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
					window_delete, win);
	mlx_hook((*win)->mlx_win, KEYPRESS, KEYPRESSMASK,
					window_keypress, win);
}

#define	WIDTH	960
#define	HEIGHT	540

int	main(int argc, char **argv)
{
	t_window	*window;
	t_image		*image;

	if (argc != 2 && argc != 3)
		error_usage(argv[0]);
	window = window_new(WIDTH, HEIGHT, "Hello, World!");
	image = window_new_image(window, WIDTH, HEIGHT);
	make_my_image(image, WIDTH, HEIGHT);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		image_print_bmp(image, argv[0], argv[1]);
	window_put_next_image(window);
	hook(&window);
	mlx_loop(window->mlx);
}

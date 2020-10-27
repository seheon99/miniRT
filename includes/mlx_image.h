/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:58:10 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 01:10:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

# include "mlx_color.h"

struct	s_image
{
	void			*mlx_img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_image	*next_img;
};
typedef	struct s_image	t_image;

int		image_pixel_put(t_image *img, int x, int y, t_color color);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:30:39 by seyu              #+#    #+#             */
/*   Updated: 2020/10/28 01:19:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLOR_H
# define MLX_COLOR_H

typedef	int	t_color;

t_color	color_create_trgb(int t, int r, int g, int b);
t_color	color_get_t(t_color trgb);
t_color	color_get_r(t_color trgb);
t_color	color_get_g(t_color trgb);
t_color	color_get_b(t_color trgb);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric_reflectance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:50:57 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 19:52:30 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material/dielectric.h"

double	dielectric_reflactance(t_dielectric *dielectric,
									double cosine, double ref_idx)
{
	double	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

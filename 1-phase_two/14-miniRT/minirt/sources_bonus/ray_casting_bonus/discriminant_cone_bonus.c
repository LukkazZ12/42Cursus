/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant_cone_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:51:48 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/29 18:39:39 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_discriminant	calculate_discriminant_ray_cone(t_ray ray)
{
	t_discriminant	discriminant;

	discriminant.a = ray.vector.x * ray.vector.x - ray.vector.y * ray.vector.y \
		+ ray.vector.z * ray.vector.z;
	discriminant.b = 2 * ray.point.x * ray.vector.x \
		- 2 * ray.point.y * ray.vector.y + 2 * ray.point.z * ray.vector.z;
	discriminant.c = ray.point.x * ray.point.x - ray.point.y * ray.point.y \
		+ ray.point.z * ray.point.z;
	if (are_equals(discriminant.a, 0) && are_equals(discriminant.b, 0))
		discriminant.discriminant = -1;
	else if (are_equals(discriminant.a, 0))
		discriminant.t[0] = -discriminant.c / 2 * discriminant.b;
	else
	{
		discriminant.discriminant = discriminant.b * discriminant.b \
			- 4 * discriminant.a * discriminant.c;
		discriminant.t[0] = (-discriminant.b \
			- sqrt(discriminant.discriminant)) / (2 * discriminant.a);
		discriminant.t[1] = (-discriminant.b \
			+ sqrt(discriminant.discriminant)) / (2 * discriminant.a);
	}
	return (discriminant);
}

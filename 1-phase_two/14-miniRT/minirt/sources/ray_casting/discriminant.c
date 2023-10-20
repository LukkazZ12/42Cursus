/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:05:30 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/29 18:32:01 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_discriminant	calculate_discriminant_ray_sphere(t_ray ray)
{
	t_discriminant	discriminant;

	discriminant.vector = subtract_tuples(ray.point, create_point(0, 0, 0));
	discriminant.a = calculate_dot_product(ray.vector, ray.vector);
	discriminant.b = 2 * calculate_dot_product(ray.vector, \
		discriminant.vector);
	discriminant.c = calculate_dot_product(discriminant.vector, \
		discriminant.vector) - 1;
	discriminant.discriminant = discriminant.b * discriminant.b - 4 \
		* discriminant.a * discriminant.c;
	discriminant.t[0] = (-discriminant.b \
		- sqrt(discriminant.discriminant)) / (2 * discriminant.a);
	discriminant.t[1] = (-discriminant.b \
		+ sqrt(discriminant.discriminant)) / (2 * discriminant.a);
	return (discriminant);
}

t_discriminant	calculate_discriminant_ray_cylinder(t_ray ray)
{
	t_discriminant	discriminant;

	discriminant.a = ray.vector.x * ray.vector.x + ray.vector.z * ray.vector.z;
	if (are_equals(discriminant.a, 0))
		discriminant.discriminant = -1;
	else
	{
		discriminant.b = 2 * ray.point.x * ray.vector.x + \
			2 * ray.point.z * ray.vector.z;
		discriminant.c = ray.point.x * ray.point.x \
			+ ray.point.z * ray.point.z - 1;
		discriminant.discriminant = discriminant.b * discriminant.b \
			- 4 * discriminant.a * discriminant.c;
		discriminant.t[0] = (-discriminant.b \
			- sqrt(discriminant.discriminant)) / (2 * discriminant.a);
		discriminant.t[1] = (-discriminant.b \
			+ sqrt(discriminant.discriminant)) / (2 * discriminant.a);
	}
	return (discriminant);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:45:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/12 16:54:06 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	create_ray(t_rt *rt, double i, double j)
{
	t_coordinates	pixel;
	t_coordinates	point;
	t_coordinates	vector;
	double			x;
	double			y;

	x = rt->render.half_width - rt->render.pixel_size * (i + 0.5);
	y = rt->render.half_height - rt->render.pixel_size * (j + 0.5);
	pixel = multiply_matrix_tuple(rt->render.inverse, create_point(x, y, -1));
	point = multiply_matrix_tuple(rt->render.inverse, create_point(0, 0, 0));
	vector = normalize_vector(subtract_tuples(pixel, point));
	return ((t_ray){point, vector});
}

t_coordinates	calculate_ray_position(t_ray ray, double t)
{
	return (add_tuples(ray.point, multiply_tuple(t, ray.vector)));
}

t_ray	transform_ray(t_ray ray, double **matrix)
{
	t_ray	transformed_ray;

	transformed_ray.point = multiply_matrix_tuple(matrix, ray.point);
	transformed_ray.vector = multiply_matrix_tuple(matrix, ray.vector);
	return (transformed_ray);
}

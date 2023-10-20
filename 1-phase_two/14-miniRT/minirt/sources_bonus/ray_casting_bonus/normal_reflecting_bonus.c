/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_reflecting_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:02:29 by byoshimo          #+#    #+#             */
/*   Updated: 2023/09/29 20:43:01 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	calculate_normal_sphere_plane(t_intersections *hit)
{
	t_coordinates	o_normal;
	t_coordinates	w_normal;

	if (hit->type == SP)
	{
		hit->o_point = multiply_matrix_tuple(hit->sphere->inverse, \
			hit->hit_point);
		o_normal = subtract_tuples(hit->o_point, create_point(0, 0, 0));
		w_normal = multiply_matrix_tuple(hit->sphere->transpose, o_normal);
	}
	else if (hit->type == PL)
		w_normal = hit->plane->vector;
	w_normal.w = 0;
	hit->normal = normalize_vector(w_normal);
}

static void	calculate_normal_cylinder(t_intersections *hit)
{
	double			dist;
	t_coordinates	o_normal;
	t_coordinates	w_normal;

	hit->o_point = multiply_matrix_tuple(hit->cylinder->inverse, \
		hit->hit_point);
	dist = hit->o_point.x * hit->o_point.x + hit->o_point.z * hit->o_point.z;
	if (dist < 1 && are_equals(hit->o_point.y, hit->cylinder->max))
		o_normal = create_vector(0, 1, 0);
	else if (dist < 1 && are_equals(hit->o_point.y, hit->cylinder->min))
		o_normal = create_vector(0, -1, 0);
	else
		o_normal = create_vector(hit->o_point.x, 0, hit->o_point.z);
	w_normal = multiply_matrix_tuple(hit->cylinder->transpose, o_normal);
	w_normal.w = 0;
	hit->normal = normalize_vector(w_normal);
}

static void	calculate_normal_cone(t_intersections *hit)
{
	double			y;
	double			dist;
	t_coordinates	o_normal;
	t_coordinates	w_normal;

	hit->o_point = multiply_matrix_tuple(hit->cone->inverse, hit->hit_point);
	dist = hit->o_point.x * hit->o_point.x + hit->o_point.z * hit->o_point.z;
	if (dist < hit->o_point.y * hit->o_point.y \
		&& are_equals(hit->o_point.y, hit->cone->max))
		o_normal = create_vector(0, 1, 0);
	else if (dist < hit->o_point.y * hit->o_point.y \
		&& are_equals(hit->o_point.y, hit->cone->min))
		o_normal = create_vector(0, -1, 0);
	else
	{
		y = sqrt(dist);
		if (hit->o_point.y > 0)
			y = -y;
		o_normal = create_vector(hit->o_point.x, y, hit->o_point.z);
	}
	w_normal = multiply_matrix_tuple(hit->cone->transpose, o_normal);
	w_normal.w = 0;
	hit->normal = normalize_vector(w_normal);
}

void	calculate_normal(t_intersections *hit)
{
	if (hit->type == SP || hit->type == PL)
		calculate_normal_sphere_plane(hit);
	else if (hit->type == CY)
		calculate_normal_cylinder(hit);
	else if (hit->type == CO)
		calculate_normal_cone(hit);
}

t_coordinates	calculate_reflecting_vector(t_coordinates light, \
					t_coordinates normal)
{
	return (subtract_tuples(light, \
		multiply_tuple(2 * calculate_dot_product(light, normal), normal)));
}

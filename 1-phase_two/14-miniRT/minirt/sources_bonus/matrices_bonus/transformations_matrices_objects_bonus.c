/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_matrices_objects_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:12:38 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/29 18:48:10 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	transform_spheres(t_rt *rt)
{
	int		i;
	double	r;
	double	**scaling;
	double	**translation;
	double	**product;

	i = 0;
	while (i < rt->num_sp)
	{
		r = rt->spheres[i].diameter / 2;
		scaling = create_scaling_matrix(create_point(r, r, r));
		translation = create_translation_matrix(rt->spheres[i].point);
		product = multiply_matrices(translation, scaling);
		free_matrix(&scaling);
		free_matrix(&translation);
		rt->spheres[i].inverse = invert_matrix(product);
		free_matrix(&product);
		rt->spheres[i].transpose = transpose_matrix(rt->spheres[i].inverse);
		i++;
	}
}

static void	transform_planes(t_rt *rt)
{
	int		i;
	double	**rotation;
	double	**translation;
	double	**product;

	i = 0;
	while (i < rt->num_pl)
	{
		rotation = calculate_rotation_matrix(rt->planes[i].vector);
		translation = create_translation_matrix(rt->planes[i].point);
		product = multiply_matrices(translation, rotation);
		free_matrix(&rotation);
		free_matrix(&translation);
		rt->planes[i].inverse = invert_matrix(product);
		free_matrix(&product);
		rt->planes[i].transpose = transpose_matrix(rt->planes[i].inverse);
		i++;
	}
}

static void	transform_cylinders(t_rt *rt)
{
	int		i;
	double	r;
	double	**scaling_translation;
	double	**rotation_product;
	double	**product;

	i = 0;
	while (i < rt->num_cy)
	{
		r = rt->cylinders[i].diameter / 2;
		scaling_translation = create_scaling_matrix(create_point(r, r, r));
		rotation_product = calculate_rotation_matrix(rt->cylinders[i].vector);
		product = multiply_matrices(rotation_product, scaling_translation);
		free_matrix(&scaling_translation);
		free_matrix(&rotation_product);
		scaling_translation = create_translation_matrix(rt->cylinders[i].point);
		rotation_product = multiply_matrices(scaling_translation, product);
		free_matrix(&scaling_translation);
		free_matrix(&product);
		rt->cylinders[i].inverse = invert_matrix(rotation_product);
		free_matrix(&rotation_product);
		rt->cylinders[i].transpose = transpose_matrix(rt->cylinders[i].inverse);
		i++;
	}
}

static void	transform_cones(t_rt *rt)
{
	int		i;
	double	**translation;
	double	**rotation;
	double	**product;

	i = 0;
	while (i < rt->num_co)
	{
		translation = create_translation_matrix(rt->cones[i].point);
		rotation = calculate_rotation_matrix(rt->cones[i].vector);
		product = multiply_matrices(translation, rotation);
		free_matrix(&translation);
		free_matrix(&rotation);
		rt->cones[i].inverse = invert_matrix(product);
		free_matrix(&product);
		rt->cones[i].transpose = transpose_matrix(rt->cones[i].inverse);
		i++;
	}
}

void	init_object_matrices(t_rt *rt)
{
	if (rt->num_sp)
		transform_spheres(rt);
	if (rt->num_pl)
		transform_planes(rt);
	if (rt->num_cy)
		transform_cylinders(rt);
	if (rt->num_co)
		transform_cones(rt);
}

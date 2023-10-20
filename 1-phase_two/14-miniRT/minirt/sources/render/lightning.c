/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:49:38 by byoshimo          #+#    #+#             */
/*   Updated: 2023/10/03 17:36:49 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	calculate_diffuse(t_rt *rt, t_color effective_color, int i)
{
	double			light_dot_normal;
	t_color			aux_color;
	t_coordinates	light_vector;

	aux_color = (t_color){0, 0, 0};
	light_vector = normalize_vector(subtract_tuples(rt->lights[i].point, \
		rt->hit->hit_point));
	light_dot_normal = calculate_dot_product(light_vector, rt->hit->normal);
	if (light_dot_normal >= -EPSILON)
		aux_color = multiply_color_by_scalar(rt->material.diffuse \
			* light_dot_normal, effective_color);
	return (aux_color);
}

static int	is_shadowed(t_rt *rt, int i)
{
	double			distance;
	t_coordinates	vector;
	t_ray			ray;
	t_intersections	*hit;

	vector = subtract_tuples(rt->lights[i].point, rt->hit->over_point);
	distance = calculate_vector_magnitude(vector);
	vector = normalize_vector(vector);
	ray = (t_ray){rt->hit->over_point, vector};
	intersections(rt, ray, &rt->shadows);
	hit = get_hit(rt->shadows);
	if (hit && hit->t < distance)
	{
		free_intersections(&rt->shadows);
		return (1);
	}
	free_intersections(&rt->shadows);
	return (0);
}

static t_color	get_object_color(t_rt *rt)
{
	if (rt->hit->type == SP)
		return (rt->hit->sphere->color);
	else if (rt->hit->type == PL)
		return (rt->hit->plane->color);
	return (rt->hit->cylinder->color);
}

t_color	lightning(t_rt *rt)
{
	int				i;
	t_color			effective_color;
	t_color			obj_color;
	t_color			color;
	t_color			aux_color;

	color = (t_color){0, 0, 0};
	obj_color = get_object_color(rt);
	i = -1;
	while (++i < rt->num_lights)
	{
		aux_color = (t_color){0, 0, 0};
		effective_color = multiply_colors(obj_color, \
			multiply_color_by_scalar(rt->lights[i].brightness, \
			(t_color){255, 255, 255}));
		aux_color = add_colors(multiply_color_by_scalar(rt->material.ambient, \
			effective_color), multiply_colors(obj_color, \
			multiply_color_by_scalar(rt->amb_light.ratio, \
			rt->amb_light.color)));
		if (!is_shadowed(rt, i))
			aux_color = add_colors(aux_color, \
				calculate_diffuse(rt, effective_color, i));
		color = add_colors(aux_color, color);
	}
	return (color);
}

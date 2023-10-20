/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:48:55 by byoshimo          #+#    #+#             */
/*   Updated: 2023/09/05 21:22:34 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_vector_magnitude(t_coordinates v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2)));
}

t_coordinates	normalize_vector(t_coordinates v)
{
	return (divide_tuple(calculate_vector_magnitude(v), v));
}

double	calculate_dot_product(t_coordinates v, t_coordinates u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w);
}

t_coordinates	calculate_cross_product(t_coordinates v, t_coordinates u)
{
	return ((t_coordinates){v.y * u.z - v.z * u.y, v.z * u.x - v.x * u.z, \
		v.x * u.y - v.y * u.x, 0});
}

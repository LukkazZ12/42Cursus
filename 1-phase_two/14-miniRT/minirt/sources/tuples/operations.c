/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:56:54 by byoshimo          #+#    #+#             */
/*   Updated: 2023/08/30 22:00:14 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coordinates	add_tuples(t_coordinates a, t_coordinates b)
{
	return ((t_coordinates){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_coordinates	subtract_tuples(t_coordinates a, t_coordinates b)
{
	return ((t_coordinates){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
}

t_coordinates	negate_tuple(t_coordinates a)
{
	return ((t_coordinates){-a.x, -a.y, -a.z, -a.w});
}

t_coordinates	multiply_tuple(double scalar, t_coordinates a)
{
	return ((t_coordinates){scalar * a.x, scalar * a.y, \
		scalar * a.z, scalar * a.w});
}

t_coordinates	divide_tuple(double scalar, t_coordinates a)
{
	return ((t_coordinates){a.x / scalar, a.y / scalar, \
		a.z / scalar, a.w / scalar});
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:52:16 by byoshimo          #+#    #+#             */
/*   Updated: 2023/09/02 15:34:14 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	are_equals(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

int	are_equals_tuples(t_coordinates a, t_coordinates b)
{
	return (are_equals(a.x, b.x) && are_equals(a.y, b.y) \
		&& are_equals(a.z, b.z) && are_equals(a.w, b.w));
}

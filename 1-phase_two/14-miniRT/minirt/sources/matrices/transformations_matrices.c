/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:19 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/05 20:51:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**create_translation_matrix(t_coordinates tuple)
{
	double	**translation;

	translation = create_identity_matrix(4);
	translation[0][3] = tuple.x;
	translation[1][3] = tuple.y;
	translation[2][3] = tuple.z;
	return (translation);
}

double	**create_scaling_matrix(t_coordinates tuple)
{
	double	**scaling;

	scaling = create_identity_matrix(4);
	scaling[0][0] = tuple.x;
	scaling[1][1] = tuple.y;
	scaling[2][2] = tuple.z;
	return (scaling);
}

double	**create_rotation_matrix(int axis, double angle)
{
	int		y;
	double	**rotation;

	y = 0;
	if (axis == Y_AXIS)
	{
		axis = 0;
		y = 1;
	}
	rotation = create_identity_matrix(4);
	rotation[axis][axis] = cos(angle);
	rotation[axis][axis + 1 + y] = pow(-1, y + 1) * sin(angle);
	rotation[axis + 1 + y][axis] = pow(-1, y) * sin(angle);
	rotation[axis + 1 + y][axis + 1 + y] = cos(angle);
	return (rotation);
}

double	**create_shearing_matrix(double proportions[6])
{
	double	**shearing;

	shearing = create_identity_matrix(4);
	shearing[0][1] = proportions[0];
	shearing[0][2] = proportions[1];
	shearing[1][0] = proportions[2];
	shearing[1][2] = proportions[3];
	shearing[2][0] = proportions[4];
	shearing[2][1] = proportions[5];
	return (shearing);
}

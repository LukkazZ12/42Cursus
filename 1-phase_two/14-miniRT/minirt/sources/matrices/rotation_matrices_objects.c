/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices_objects.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:14:19 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/25 14:14:29 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	**calculate_z_y_rotation_matrix(t_coordinates vector)
{
	double	**rotation_z;
	double	**rotation_y;
	double	**rotation;

	rotation_z = create_rotation_matrix(Z_AXIS, -M_PI / 2);
	rotation_y = create_rotation_matrix(Y_AXIS, atan(-vector.x / vector.z));
	rotation = multiply_matrices(rotation_y, rotation_z);
	free_matrix(&rotation_z);
	free_matrix(&rotation_y);
	return (rotation);
}

static double	**calculate_z_x_rotation_matrix(t_coordinates vector)
{
	double	**rotation_x;
	double	**rotation_z;
	double	**rotation;

	rotation_x = create_rotation_matrix(X_AXIS, atan(-vector.z / vector.y));
	rotation_z = create_rotation_matrix(Z_AXIS, atan(-vector.x / vector.y));
	rotation = multiply_matrices(rotation_z, rotation_x);
	free_matrix(&rotation_x);
	free_matrix(&rotation_z);
	return (rotation);
}

double	**calculate_rotation_matrix(t_coordinates vector)
{
	if (are_equals_tuples(create_vector(0, 1, 0), vector))
		return (create_identity_matrix(4));
	else if (are_equals_tuples(create_vector(0, -1, 0), vector))
		return (create_rotation_matrix(X_AXIS, M_PI));
	else if (are_equals_tuples(create_vector(1, 0, 0), vector))
		return (create_rotation_matrix(Z_AXIS, -M_PI / 2));
	else if (are_equals_tuples(create_vector(-1, 0, 0), vector))
		return (create_rotation_matrix(Z_AXIS, M_PI / 2));
	else if (are_equals_tuples(create_vector(0, 0, 1), vector))
		return (create_rotation_matrix(X_AXIS, M_PI / 2));
	else if (are_equals_tuples(create_vector(0, 0, -1), vector))
		return (create_rotation_matrix(X_AXIS, -M_PI / 2));
	if (are_equals(vector.y, 0))
		return (calculate_z_y_rotation_matrix(vector));
	else
		return (calculate_z_x_rotation_matrix(vector));
}

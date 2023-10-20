/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:20:27 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/22 18:29:01 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**create_matrix(int size)
{
	int		i;
	double	**matrix;

	matrix = (double **)ft_calloc(size + 1, sizeof(double *));
	i = 0;
	while (i < size)
	{
		matrix[i] = (double *)ft_calloc(size, sizeof(double));
		i++;
	}
	return (matrix);
}

double	**create_identity_matrix(int size)
{
	int		i;
	double	**matrix;

	matrix = create_matrix(size);
	i = 0;
	while (i < size)
	{
		matrix[i][i] = 1;
		i++;
	}
	return (matrix);
}

double	**transpose_matrix(double **matrix)
{
	int		i;
	int		j;
	int		size;
	double	**trans_matrix;

	size = matrix_length(matrix);
	trans_matrix = create_matrix(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			trans_matrix[j][i] = matrix [i][j];
			j++;
		}
		i++;
	}
	return (trans_matrix);
}

double	**invert_matrix(double **matrix)
{
	int		i;
	int		size;
	double	determinant;
	double	**trans_cofactor;
	double	**inverse;

	size = matrix_length(matrix);
	determinant = calculate_determinant(matrix);
	if (!determinant)
	{
		inverse = create_identity_matrix(size);
		i = -1;
		while (++i < size)
			inverse[i][i] = 0;
		return (inverse);
	}
	inverse = calculate_cofactor_matrix(matrix);
	trans_cofactor = transpose_matrix(inverse);
	free_matrix(&inverse);
	inverse = multiply_matrix_by_scalar(1 / determinant, trans_cofactor);
	free_matrix(&trans_cofactor);
	return (inverse);
}

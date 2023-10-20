/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:22:11 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/06 18:35:42 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**copy_submatrix(double **matrix, int size, int i, int j)
{
	int		k;
	int		l;
	double	**submatrix;

	submatrix = create_matrix(size - 1);
	k = 0;
	while (k < size - 1)
	{
		l = 0;
		while (l < size - 1)
		{
			if (k >= i && l >= j)
				submatrix[k][l] = matrix[k + 1][l + 1];
			else if (k >= i && l < j)
				submatrix[k][l] = matrix[k + 1][l];
			else if (k < i && l >= j)
				submatrix[k][l] = matrix[k][l + 1];
			else
				submatrix[k][l] = matrix[k][l];
			l++;
		}
		k++;
	}
	return (submatrix);
}

double	calculate_determinant(double **matrix)
{
	int		j;
	int		size;
	double	determinant;
	double	**submatrix;
	double	minor;

	size = matrix_length(matrix);
	if (size == 1)
		return (matrix[0][0]);
	determinant = 0;
	j = 0;
	while (j < size)
	{
		submatrix = copy_submatrix(matrix, size, 0, j);
		minor = calculate_determinant(submatrix);
		if (j % 2)
			determinant -= matrix[0][j] * minor;
		else
			determinant += matrix[0][j] * minor;
		free_matrix(&submatrix);
		j++;
	}
	return (determinant);
}

double	**calculate_cofactor_matrix(double **matrix)
{
	int		i;
	int		j;
	int		size;
	double	**submatrix;
	double	**cofactor;

	size = matrix_length(matrix);
	cofactor = create_identity_matrix(size);
	if (size == 1)
		return (cofactor);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			submatrix = copy_submatrix(matrix, size, i, j);
			cofactor[i][j] = calculate_determinant(submatrix);
			if ((i + j) % 2)
				cofactor[i][j] *= -1;
			free_matrix(&submatrix);
		}
	}
	return (cofactor);
}

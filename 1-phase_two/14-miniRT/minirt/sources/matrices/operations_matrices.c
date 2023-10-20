/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_matrices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:27:33 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/06 16:52:06 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	**multiply_matrices(double **A, double **B)
{
	int		i;
	int		j;
	int		k;
	int		size;
	double	**product;

	size = matrix_length(A);
	product = create_matrix(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			k = 0;
			while (k < size)
			{
				product[i][j] += A[i][k] * B[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (product);
}

t_coordinates	multiply_matrix_tuple(double **A, t_coordinates t)
{
	t_coordinates	product;

	product.x = A[0][0] * t.x + A[0][1] * t.y + A[0][2] * t.z + A[0][3] * t.w;
	product.y = A[1][0] * t.x + A[1][1] * t.y + A[1][2] * t.z + A[1][3] * t.w;
	product.z = A[2][0] * t.x + A[2][1] * t.y + A[2][2] * t.z + A[2][3] * t.w;
	product.w = A[3][0] * t.x + A[3][1] * t.y + A[3][2] * t.z + A[3][3] * t.w;
	return (product);
}

double	**multiply_matrix_by_scalar(double scalar, double **matrix)
{
	int		i;
	int		j;
	int		size;
	double	**product;

	size = matrix_length(matrix);
	product = create_matrix(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			product[i][j] = scalar * matrix[i][j];
			j++;
		}
		i++;
	}
	return (product);
}

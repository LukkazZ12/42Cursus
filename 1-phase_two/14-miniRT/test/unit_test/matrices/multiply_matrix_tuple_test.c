#include "unit_test.h"

Test(matrices, test_multiply_matrix_tuple_C_null_tuple) {
	double			**C = create_matrix(4);
	t_coordinates	tuple = {0, 0, 0, 0};
	int				size = 4;
	int				i = 0;
	int				j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			C[i][j] = i + j;
			j++;
		}
		i++;
	}
	
	t_coordinates	expected = {0, 0, 0, 0};
	t_coordinates	product = multiply_matrix_tuple(C, tuple);
	int				result = are_equals_tuples(expected, product);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
}

Test(matrices, test_multiply_matrix_tuple_C_tuple) {
	double			**C = create_matrix(4);
	t_coordinates	tuple = {1, 2, 3, 4};
	int				size = 4;
	int				i = 0;
	int				j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			C[i][j] = i + j;
			j++;
		}
		i++;
	}
	
	t_coordinates	expected = {20, 30, 40, 50};
	t_coordinates	product = multiply_matrix_tuple(C, tuple);
	int				result = are_equals_tuples(expected, product);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
}

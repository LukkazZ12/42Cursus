#include "unit_test.h"

Test(matrices, test_multiply_matrices_C_D_1) {
	int		size = 1;
	double	**C = create_matrix(size);
	double	**D = create_matrix(size);
	double	**E = create_matrix(size);

	C[0][0] = 120;
	D[0][0] = 10;
	E[0][0] = 1200;
	double	**product = multiply_matrices(C, D);
	int		result = are_equals_matrices(product, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
	free_matrix(&E);
	free_matrix(&product);
}

Test(matrices, test_multiply_matrices_C_D_2) {
	int		size = 2;
	double	**C = create_matrix(size);
	double	**D = create_matrix(size);
	double	**E = create_matrix(size);
	int		i = 0;
	int		j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			C[i][j] = i + j;
			D[i][j] = i + j;
			j++;
		}
		i++;
	}
	E[0][0] = 1;
	E[0][1] = 2;
	E[1][0] = 2;
	E[1][1] = 5;
	double	**product = multiply_matrices(C, D);
	int		result = are_equals_matrices(product, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
	free_matrix(&E);
	free_matrix(&product);
}

Test(matrices, test_multiply_matrices_C_D_3) {
	int		size = 3;
	double	**C = create_matrix(3);
	double	**D = create_matrix(3);
	double	**E = create_matrix(3);
	int		i = 0;
	int		j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			C[i][j] = i + j;
			D[i][j] = i + j;
			j++;
		}
		i++;
	}
	E[0][0] = 5;
	E[0][1] = 8;
	E[0][2] = 11;
	E[1][0] = 8;
	E[1][1] = 14;
	E[1][2] = 20;
	E[2][0] = 11;
	E[2][1] = 20;
	E[2][2] = 29;
	double	**product = multiply_matrices(C, D);
	int		result = are_equals_matrices(product, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
	free_matrix(&E);
	free_matrix(&product);
}

Test(matrices, test_multiply_matrices_C_D_5) {
	double	**C = create_matrix(5);
	double	**D = create_matrix(5);
	double	**E = create_matrix(5);
	int		size = 5;
	int		i = 0;
	int		j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			C[i][j] = i + j;
			D[i][j] = i + j;
			j++;
		}
		i++;
	}
	E[0][0] = 30;
	E[0][1] = 40;
	E[0][2] = 50;
	E[0][3] = 60;
	E[0][4] = 70;
	E[1][0] = 40;
	E[1][1] = 55;
	E[1][2] = 70;
	E[1][3] = 85;
	E[1][4] = 100;
	E[2][0] = 50;
	E[2][1] = 70;
	E[2][2] = 90;
	E[2][3] = 110;
	E[2][4] = 130;
	E[3][0] = 60;
	E[3][1] = 85;
	E[3][2] = 110;
	E[3][3] = 135;
	E[3][4] = 160;
	E[4][0] = 70;
	E[4][1] = 100;
	E[4][2] = 130;
	E[4][3] = 160;
	E[4][4] = 190;
	double	**product = multiply_matrices(C, D);
	int		result = are_equals_matrices(product, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
	free_matrix(&E);
	free_matrix(&product);
}

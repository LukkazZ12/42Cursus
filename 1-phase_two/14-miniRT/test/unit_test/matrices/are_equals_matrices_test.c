#include "unit_test.h"

Test(matrices, test_are_equals_matrices_A_B_1_null) {
	double	**A = create_matrix(1);
	double	**B = create_matrix(1);

	int		result = are_equals_matrices(A, B);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&A);
	free_matrix(&B);
}

Test(matrices, test_are_equals_matrices_A_B_1) {
	double	**A = create_matrix(1);
	double	**B = create_matrix(1);

	A[0][0] = 45;
	B[0][0] = 45;

	int		result = are_equals_matrices(A, B);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&A);
	free_matrix(&B);
}

Test(matrices, test_are_equals_matrices_A_B_2_null) {
	double	**A = create_matrix(2);
	double	**B = create_matrix(2);

	int		result = are_equals_matrices(A, B);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&A);
	free_matrix(&B);
}

Test(matrices, test_are_equals_matrices_A_B_2) {
	double	**A = create_matrix(2);
	double	**B = create_matrix(2);

	A[0][0] = 45;
	A[0][1] = -5645;
	A[1][0] = 45.65;
	A[1][1] = 45/85;
	B[0][0] = 45;
	B[0][1] = -5645;
	B[1][0] = 45.65;
	B[1][1] = 45/85;

	int		result = are_equals_matrices(A, B);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&A);
	free_matrix(&B);
}

Test(matrices, test_are_equals_matrices_A_B) {
	double	**A = create_matrix(4);
	double	**B = create_matrix(4);

	int		result = are_equals_matrices(A, B);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&A);
	free_matrix(&B);
}

Test(matrices, test_are_equals_matrices_C_D) {
	double	**C = create_matrix(4);
	double	**D = create_matrix(4);
	int		i = 0;
	int		j;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			C[i][j] = i + j;
			D[i][j] = i + j;
			j++;
		}
		i++;
	}

	int		result = are_equals_matrices(C, D);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
}

Test(matrices, test_are_equals_matrices_C_D_double) {
	double	**C = create_matrix(4);
	double	**D = create_matrix(4);
	int		i = 0;
	int		j;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			C[i][j] = 6.8;
			D[i][j] = 6.8;
			j++;
		}
		i++;
	}

	int		result = are_equals_matrices(C, D);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
}

Test(matrices, test_are_equals_matrices_C_D_not_equals) {
	double	**C = create_matrix(4);
	double	**D = create_matrix(4);
	int		i = 0;
	int		j;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			C[i][j] = i + j;
			D[i][j] = i + j;
			j++;
		}
		i++;
	}
	C[2][2] = -3;

	int		result = are_equals_matrices(C, D);

	cr_assert(epsilon_eq(flt, 0, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
}

Test(matrices, test_are_equals_matrices_C_D_not_equals_2) {
	double	**C = create_matrix(3);
	double	**D = create_matrix(4);

	int		result = are_equals_matrices(C, D);

	cr_assert(epsilon_eq(flt, 0, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
}

Test(matrices, test_are_equals_matrices_C_D_not_equals_3) {
	double	**C = create_matrix(3);
	double	**D = create_matrix(4);

	int		result = are_equals_matrices(C, D);

	cr_assert(epsilon_eq(flt, 0, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
}

#include "unit_test.h"

Test(matrices, test_copy_submatrix_2_0) {
	int		size = 2;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size - 1);

	E[0][0] = 1;
	E[0][1] = 2;
	E[1][0] = 4.9;
	E[1][1] = 2;

	F[0][0] = 2;

	double	**submatrix = copy_submatrix(E, size, 0, 0);
	int		result = are_equals_matrices(submatrix, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&submatrix);
}

Test(matrices, test_copy_submatrix_2_1) {
	int		size = 2;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size - 1);

	E[0][0] = 1;
	E[0][1] = 2;
	E[1][0] = 4.9;
	E[1][1] = 2;

	F[0][0] = 4.9;

	double	**submatrix = copy_submatrix(E, size, 0, 1);
	int		result = are_equals_matrices(submatrix, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&submatrix);
}

Test(matrices, test_copy_submatrix_3_0) {
	int		size = 3;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size - 1);

	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3.5;
	E[1][0] = 4.9;
	E[1][1] = 2;
	E[1][2] = 3;
	E[2][0] = 1.2;
	E[2][1] = -6;
	E[2][2] = 1;

	F[0][0] = 2;
	F[0][1] = 3;
	F[1][0] = -6;
	F[1][1] = 1;

	double	**submatrix = copy_submatrix(E, size, 0, 0);
	int		result = are_equals_matrices(submatrix, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&submatrix);
}

Test(matrices, test_copy_submatrix_3_1) {
	int		size = 3;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size - 1);

	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3.5;
	E[1][0] = 4.9;
	E[1][1] = 2;
	E[1][2] = 3;
	E[2][0] = 1.2;
	E[2][1] = -6;
	E[2][2] = 1;

	F[0][0] = 4.9;
	F[0][1] = 3;
	F[1][0] = 1.2;
	F[1][1] = 1;

	double	**submatrix = copy_submatrix(E, size, 0, 1);
	int		result = are_equals_matrices(submatrix, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&submatrix);
}

Test(matrices, test_copy_submatrix_3_2) {
	int		size = 3;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size - 1);

	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3.5;
	E[1][0] = 4.9;
	E[1][1] = 2;
	E[1][2] = 3;
	E[2][0] = 1.2;
	E[2][1] = -6;
	E[2][2] = 1;

	F[0][0] = 4.9;
	F[0][1] = 2;
	F[1][0] = 1.2;
	F[1][1] = -6;

	double	**submatrix = copy_submatrix(E, size, 0, 2);
	int		result = are_equals_matrices(submatrix, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&submatrix);
}

Test(matrices, test_copy_submatrix_4_0) {
	int		size = 4;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size - 1);

	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3.5;
	E[0][3] = 3;
	E[1][0] = 4.9;
	E[1][1] = 2;
	E[1][2] = 3;
	E[1][3] = 10;
	E[2][0] = 1.2;
	E[2][1] = -6;
	E[2][2] = 1;
	E[2][3] = -1;
	E[3][0] = 1;
	E[3][1] = 6;
	E[3][2] = 68;
	E[3][3] = 100;

	F[0][0] = 2;
	F[0][1] = 3;
	F[0][2] = 10;
	F[1][0] = -6;
	F[1][1] = 1;
	F[1][2] = -1;
	F[2][0] = 6;
	F[2][1] = 68;
	F[2][2] = 100;

	double	**submatrix = copy_submatrix(E, size, 0, 0);
	int		result = are_equals_matrices(submatrix, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&submatrix);
}

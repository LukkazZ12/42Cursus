#include "unit_test.h"

Test(matrices, test_calculate_cofactor_matrix_1) {
	int		size = 1;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size);

	E[0][0] = -5;

	F[0][0] = 1;

	double	**cofactor = calculate_cofactor_matrix(E);
	int		result = are_equals_matrices(cofactor, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&cofactor);
}

Test(matrices, test_calculate_cofactor_matrix_2) {
	int		size = 2;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size);

	E[0][0] = -5;
	E[0][1] = 2;
	E[1][0] = 1;
	E[1][1] = -5;

	F[0][0] = -5;
	F[0][1] = -1;
	F[1][0] = -2;
	F[1][1] = -5;

	double	**cofactor = calculate_cofactor_matrix(E);
	int		result = are_equals_matrices(cofactor, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&cofactor);
}

Test(matrices, test_calculate_cofactor_matrix_3) {
	int		size = 3;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 25;
	E[0][2] = 2.9;
	E[1][0] = -5;
	E[1][1] = 21;
	E[1][2] = 0;
	E[2][0] = 3.4;
	E[2][1] = -1;
	E[2][2] = -69;

	F[0][0] = -1449;
	F[0][1] = -345;
	F[0][2] = -66.4;
	F[1][0] = 1722.1;
	F[1][1] = -78.86;
	F[1][2] = 86;
	F[2][0] = -60.9;
	F[2][1] = -14.5;
	F[2][2] = 146;

	double	**cofactor = calculate_cofactor_matrix(E);
	int		result = are_equals_matrices(cofactor, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&cofactor);
}

Test(matrices, test_calculate_cofactor_matrix_4) {
	int		size = 4;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size);

	E[0][0] = -5;
	E[0][1] = 2;
	E[0][2] = 6;
	E[0][3] = -8;
	E[1][0] = 1;
	E[1][1] = -5;
	E[1][2] = 1;
	E[1][3] = 8;
	E[2][0] = 7;
	E[2][1] = 7;
	E[2][2] = -6;
	E[2][3] = -7;
	E[3][0] = 1;
	E[3][1] = -3;
	E[3][2] = 7;
	E[3][3] = 4;

	F[0][0] = 116;
	F[0][1] = -430;
	F[0][2] = -42;
	F[0][3] = -278;
	F[1][0] = 240;
	F[1][1] = -775;
	F[1][2] = -119;
	F[1][3] = -433;
	F[2][0] = 128;
	F[2][1] = -236;
	F[2][2] = -28;
	F[2][3] = -160;
	F[3][0] = -24;
	F[3][1] = 277;
	F[3][2] = 105;
	F[3][3] = 163;

	double	**cofactor = calculate_cofactor_matrix(E);
	int		result = are_equals_matrices(cofactor, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&cofactor);
}

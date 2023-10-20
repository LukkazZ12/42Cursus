#include "unit_test.h"

Test(matrices, test_invert_matrix_1) {
	int		size = 1;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size);

	E[0][0] = -5;

	F[0][0] = -0.2;

	double	**inverse = invert_matrix(E);
	int		result = are_equals_matrices(inverse, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&inverse);
}

Test(matrices, test_invert_matrix_2) {
	int		size = 2;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size);

	E[0][0] = -5;
	E[0][1] = 26;
	E[1][0] = 0.1;
	E[1][1] = -50;

	F[0][0] = -0.20210;
	F[0][1] = -0.10509;
	F[1][0] = -0.00040;
	F[1][1] = -0.02021;

	double	**inverse = invert_matrix(E);
	int		result = are_equals_matrices(inverse, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&inverse);
}

Test(matrices, test_invert_matrix_3) {
	int		size = 3;
	double	**E = create_matrix(size);
	double	**F = create_matrix(size);

	E[0][0] = -5;
	E[0][1] = 2;
	E[0][2] = 6;
	E[1][0] = 1;
	E[1][1] = -5;
	E[1][2] = 1;
	E[2][0] = 7;
	E[2][1] = 7;
	E[2][2] = -6;

	F[0][0] = 0.14110;
	F[0][1] = 0.33128;
	F[0][2] = 0.19631;
	F[1][0] = 0.07975;
	F[1][1] = -0.07361;
	F[1][2] = 0.06748;
	F[2][0] = 0.25766;
	F[2][1] = 0.30061;
	F[2][2] = 0.14110;

	double	**inverse = invert_matrix(E);
	int		result = are_equals_matrices(inverse, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&inverse);
}

Test(matrices, test_invert_matrix_4) {
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

	F[0][0] = 0.21805;
	F[0][1] = 0.45113;
	F[0][2] = 0.24060;
	F[0][3] = -0.04511;
	F[1][0] = -0.80827;
	F[1][1] = -1.45677;
	F[1][2] = -0.44361;
	F[1][3] = 0.52068;
	F[2][0] = -0.07895;
	F[2][1] = -0.22368;
	F[2][2] = -0.05263;
	F[2][3] = 0.19737;
	F[3][0] = -0.52256;
	F[3][1] = -0.81391;
	F[3][2] = -0.30075;
	F[3][3] = 0.30639;

	double	**inverse = invert_matrix(E);
	int		result = are_equals_matrices(inverse, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&inverse);
}

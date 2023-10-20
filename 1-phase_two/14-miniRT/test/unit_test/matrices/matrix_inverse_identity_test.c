#include "unit_test.h"

Test(matrices, test_matrix_inverse_identity_1) {
	int		size = 1;
	double	**E = create_matrix(size);
	double	**F = create_identity_matrix(size);

	E[0][0] = -168.9;

	double	**inverse = invert_matrix(E);
	double	**product = multiply_matrices(E, inverse);
	int		result = are_equals_matrices(product, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&product);
	free_matrix(&inverse);
}

Test(matrices, test_matrix_inverse_identity_2) {
	int		size = 2;
	double	**E = create_matrix(size);
	double	**F = create_identity_matrix(size);

	E[0][0] = 0.32;
	E[0][1] = 28;
	E[1][0] = -168.9;
	E[1][1] = -5;

	double	**inverse = invert_matrix(E);
	double	**product = multiply_matrices(E, inverse);
	int		result = are_equals_matrices(product, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&product);
	free_matrix(&inverse);
}

Test(matrices, test_matrix_inverse_identity_3) {
	int		size = 3;
	double	**E = create_matrix(size);
	double	**F = create_identity_matrix(size);

	E[0][0] = 2;
	E[0][1] = 2;
	E[0][2] = 6;
	E[1][0] = 1;
	E[1][1] = -5;
	E[1][2] = 1;
	E[2][0] = -7;
	E[2][1] = 7;
	E[2][2] = -6;

	double	**inverse = invert_matrix(E);
	double	**product = multiply_matrices(E, inverse);
	int		result = are_equals_matrices(product, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&product);
	free_matrix(&inverse);
}

Test(matrices, test_matrix_inverse_identity_4) {
	int		size = 4;
	double	**E = create_matrix(size);
	double	**F = create_identity_matrix(size);

	E[0][0] = -5.99;
	E[0][1] = 2;
	E[0][2] = 6;
	E[0][3] = -8.12;
	E[1][0] = 1;
	E[1][1] = -165.12;
	E[1][2] = 1;
	E[1][3] = 8;
	E[2][0] = 7.3336;
	E[2][1] = 7;
	E[2][2] = -6.89;
	E[2][3] = -700;
	E[3][0] = 125.01;
	E[3][1] = -3;
	E[3][2] = 7.65;
	E[3][3] = 4;

	double	**inverse = invert_matrix(E);
	double	**product = multiply_matrices(E, inverse);
	int		result = are_equals_matrices(product, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&product);
	free_matrix(&inverse);
}

Test(matrices, test_matrix_inverse_identity_5) {
	int		size = 5;
	double	**E = create_matrix(size);
	double	**F = create_identity_matrix(size);

	E[0][0] = -5.99;
	E[0][1] = 2;
	E[0][2] = 6;
	E[0][3] = -8.12;
	E[0][4] = -158.12;
	E[1][0] = 1;
	E[1][1] = -165.12;
	E[1][2] = 1;
	E[1][3] = 8;
	E[1][4] = 8.6985;
	E[2][0] = 7.3336;
	E[2][1] = 7;
	E[2][2] = -6.89;
	E[2][3] = -700;
	E[2][4] = -70;
	E[3][0] = 125.01;
	E[3][1] = -3;
	E[3][2] = 7.65;
	E[3][3] = 4;
	E[3][4] = -94;
	E[4][0] = 15.01;
	E[4][1] = -43;
	E[4][2] = 7.5;
	E[4][3] = 47;
	E[4][4] = -4;

	double	**inverse = invert_matrix(E);
	double	**product = multiply_matrices(E, inverse);
	int		result = are_equals_matrices(product, F);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&product);
	free_matrix(&inverse);
}

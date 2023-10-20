#include "unit_test.h"

Test(matrices, test_calculate_determinant_1) {
	int		size = 1;
	double	**E = create_matrix(size);

	E[0][0] = 2;

	double	result = calculate_determinant(E);

	cr_assert(epsilon_eq(flt, 2, result, EPSILON));
	free_matrix(&E);
}

Test(matrices, test_calculate_determinant_2) {
	int		size = 2;
	double	**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 2;
	E[1][0] = 4.9;
	E[1][1] = 2;

	double	result = calculate_determinant(E);

	cr_assert(epsilon_eq(flt, -7.8, result, EPSILON));
	free_matrix(&E);
}

Test(matrices, test_calculate_determinant_3) {
	int		size = 3;
	double	**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3.5;
	E[1][0] = 4.9;
	E[1][1] = 2;
	E[1][2] = 3;
	E[2][0] = 1.2;
	E[2][1] = -6;
	E[2][2] = 1;

	double	result = calculate_determinant(E);

	cr_assert(epsilon_eq(flt, -93.9, result, EPSILON));
	free_matrix(&E);
}

Test(matrices, test_calculate_determinant_4) {
	int		size = 4;
	double	**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3;
	E[0][3] = 3;
	E[1][0] = 4;
	E[1][1] = 2;
	E[1][2] = 3;
	E[1][3] = 10;
	E[2][0] = 1;
	E[2][1] = -6;
	E[2][2] = 1;
	E[2][3] = -1;
	E[3][0] = 1;
	E[3][1] = 6;
	E[3][2] = 8;
	E[3][3] = 10;

	double	result = calculate_determinant(E);

	cr_assert(epsilon_eq(flt, -332, result, EPSILON));
	free_matrix(&E);
}

Test(matrices, test_calculate_determinant_5) {
	int		size = 5;
	double	**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3;
	E[0][3] = 3;
	E[0][4] = 0;
	E[1][0] = 4;
	E[1][1] = 2;
	E[1][2] = 3;
	E[1][3] = 10;
	E[1][4] = 12;
	E[2][0] = 1;
	E[2][1] = -6;
	E[2][2] = 1;
	E[2][3] = -1;
	E[2][4] = -2;
	E[3][0] = 1;
	E[3][1] = 6;
	E[3][2] = 8;
	E[3][3] = 10;
	E[3][4] = 9;
	E[4][0] = 14;
	E[4][1] = -6;
	E[4][2] = 100;
	E[4][3] = -10;
	E[4][4] = 90;

	double	result = calculate_determinant(E);

	cr_assert(epsilon_eq(flt, -96276, result, EPSILON));
	free_matrix(&E);
}

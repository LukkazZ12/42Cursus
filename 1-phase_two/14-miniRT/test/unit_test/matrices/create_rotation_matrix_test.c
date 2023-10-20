#include "unit_test.h"

Test(matrices, test_create_rotation_matrix_X_M_PI_4) {
	int		size = 4;
	double	angle = M_PI_4;

	double	**G = create_identity_matrix(size);
	G[1][1] = cos(angle);
	G[1][2] = -sin(angle);
	G[2][1] = sin(angle);
	G[2][2] = cos(angle);

	double	**rotation = create_rotation_matrix(X_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_Y_M_PI_4) {
	int		size = 4;
	double	angle = M_PI_4;

	double	**G = create_identity_matrix(size);
	G[0][0] = cos(angle);
	G[0][2] = sin(angle);
	G[2][0] = -sin(angle);
	G[2][2] = cos(angle);

	double	**rotation = create_rotation_matrix(Y_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_Z_M_PI_4) {
	int		size = 4;
	double	angle = M_PI_4;

	double	**G = create_identity_matrix(size);
	G[0][0] = cos(angle);
	G[0][1] = -sin(angle);
	G[1][0] = sin(angle);
	G[1][1] = cos(angle);

	double	**rotation = create_rotation_matrix(Z_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_X_M_PI) {
	int		size = 4;
	double	angle = M_PI;

	double	**G = create_identity_matrix(size);
	G[1][1] = cos(angle);
	G[1][2] = -sin(angle);
	G[2][1] = sin(angle);
	G[2][2] = cos(angle);

	double	**rotation = create_rotation_matrix(X_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_Y_M_PI) {
	int		size = 4;
	double	angle = M_PI;

	double	**G = create_identity_matrix(size);
	G[0][0] = cos(angle);
	G[0][2] = sin(angle);
	G[2][0] = -sin(angle);
	G[2][2] = cos(angle);

	double	**rotation = create_rotation_matrix(Y_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_Z_M_PI) {
	int		size = 4;
	double	angle = M_PI;

	double	**G = create_identity_matrix(size);
	G[0][0] = cos(angle);
	G[0][1] = -sin(angle);
	G[1][0] = sin(angle);
	G[1][1] = cos(angle);

	double	**rotation = create_rotation_matrix(Z_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_X_M_PI_3) {
	int		size = 4;
	double	angle = M_PI / 3;

	double	**G = create_identity_matrix(size);
	G[1][1] = cos(angle);
	G[1][2] = -sin(angle);
	G[2][1] = sin(angle);
	G[2][2] = cos(angle);

	double	**rotation = create_rotation_matrix(X_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_Y_M_PI_3) {
	int		size = 4;
	double	angle = M_PI / 3;

	double	**G = create_identity_matrix(size);
	G[0][0] = cos(angle);
	G[0][2] = sin(angle);
	G[2][0] = -sin(angle);
	G[2][2] = cos(angle);

	double	**rotation = create_rotation_matrix(Y_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

Test(matrices, test_create_rotation_matrix_Z_M_PI_3) {
	int		size = 4;
	double	angle = M_PI / 3;

	double	**G = create_identity_matrix(size);
	G[0][0] = cos(angle);
	G[0][1] = -sin(angle);
	G[1][0] = sin(angle);
	G[1][1] = cos(angle);

	double	**rotation = create_rotation_matrix(Z_AXIS, angle);
	int		result = are_equals_matrices(rotation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&rotation);
	free_matrix(&G);
}

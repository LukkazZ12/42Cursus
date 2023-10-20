#include "unit_test.h"

Test(matrices, test_create_identity_matrix_1) {
	int				size = 1;
	double			**Id = create_identity_matrix(size);
	double			**E = create_matrix(size);

	E[0][0] = 1;
	
	int				result = are_equals_matrices(Id, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&Id);
}

Test(matrices, test_create_identity_matrix_2) {
	int				size = 2;
	double			**Id = create_identity_matrix(size);
	double			**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 0;
	E[1][0] = 0;
	E[1][1] = 1;
	
	int				result = are_equals_matrices(Id, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&Id);
}

Test(matrices, test_create_identity_matrix_3) {
	int				size = 3;
	double			**Id = create_identity_matrix(size);
	double			**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 0;
	E[0][2] = 0;
	E[1][0] = 0;
	E[1][1] = 1;
	E[1][2] = 0;
	E[2][0] = 0;
	E[2][1] = 0;
	E[2][2] = 1;
	
	int				result = are_equals_matrices(Id, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&Id);
}

Test(matrices, test_create_identity_matrix_4) {
	int				size = 4;
	double			**Id = create_identity_matrix(size);
	double			**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 0;
	E[0][2] = 0;
	E[0][3] = 0;
	E[1][0] = 0;
	E[1][1] = 1;
	E[1][2] = 0;
	E[1][3] = 0;
	E[2][0] = 0;
	E[2][1] = 0;
	E[2][2] = 1;
	E[2][3] = 0;
	E[3][0] = 0;
	E[3][1] = 0;
	E[3][2] = 0;
	E[3][3] = 1;
	
	int				result = are_equals_matrices(Id, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&Id);
}

Test(matrices, test_create_identity_matrix_5) {
	int				size = 5;
	double			**Id = create_identity_matrix(size);
	double			**E = create_matrix(size);

	E[0][0] = 1;
	E[0][1] = 0;
	E[0][2] = 0;
	E[0][3] = 0;
	E[0][4] = 0;
	E[1][0] = 0;
	E[1][1] = 1;
	E[1][2] = 0;
	E[1][3] = 0;
	E[1][4] = 0;
	E[2][0] = 0;
	E[2][1] = 0;
	E[2][2] = 1;
	E[2][3] = 0;
	E[2][4] = 0;
	E[3][0] = 0;
	E[3][1] = 0;
	E[3][2] = 0;
	E[3][3] = 1;
	E[3][4] = 0;
	E[4][0] = 0;
	E[4][1] = 0;
	E[4][2] = 0;
	E[4][3] = 0;
	E[4][4] = 1;
	
	int				result = are_equals_matrices(Id, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&Id);
}

#include "unit_test.h"

Test(matrices, test_transpose_matrix_1) {
	int				size = 1;
	double			**C = create_matrix(size);
	double			**D = create_matrix(size);

	C[0][0] = 12;

	D[0][0] = 12;

	double			**E = transpose_matrix(C);
	
	int				result = are_equals_matrices(D, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
	free_matrix(&E);
}

Test(matrices, test_transpose_matrix_2) {
	int				size = 2;
	double			**C = create_matrix(size);
	double			**D = create_matrix(size);

	C[0][0] = 12;
	C[0][1] = -63.9;
	C[1][0] = 0;
	C[1][1] = 123;

	D[0][0] = 12;
	D[0][1] = 0;
	D[1][0] = -63.9;
	D[1][1] = 123;

	double			**E = transpose_matrix(C);
	
	int				result = are_equals_matrices(D, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&C);
	free_matrix(&D);
	free_matrix(&E);
}

Test(matrices, test_transpose_matrix_3) {
	int				size = 3;
	double			**Id = create_identity_matrix(size);
	double			**E = transpose_matrix(Id);
	
	int				result = are_equals_matrices(Id, E);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&Id);
}

Test(matrices, test_transpose_matrix_4) {
	int				size = 4;
	double			**E = create_matrix(size);
	double			**F = create_matrix(size);

	E[0][0] = 14;
	E[0][1] = 20;
	E[0][2] = 26;
	E[0][3] = 32;
	E[1][0] = 20;
	E[1][1] = 30;
	E[1][2] = 40;
	E[1][3] = 50;
	E[2][0] = 26;
	E[2][1] = 40;
	E[2][2] = 54;
	E[2][3] = 68;
	E[3][0] = 32;
	E[3][1] = 50;
	E[3][2] = 68;
	E[3][3] = 86;

	F[0][0] = 14;
	F[1][0] = 20;
	F[2][0] = 26;
	F[3][0] = 32;
	F[0][1] = 20;
	F[1][1] = 30;
	F[2][1] = 40;
	F[3][1] = 50;
	F[0][2] = 26;
	F[1][2] = 40;
	F[2][2] = 54;
	F[3][2] = 68;
	F[0][3] = 32;
	F[1][3] = 50;
	F[2][3] = 68;
	F[3][3] = 86;

	double			**G = transpose_matrix(E);
	int				result = are_equals_matrices(F, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&E);
	free_matrix(&F);
	free_matrix(&G);
}

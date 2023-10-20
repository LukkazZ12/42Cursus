#include "unit_test.h"

Test(matrices, test_create_shearing_matrix) {
	int		size = 4;
	double	proportions[6] = {12.9, 33.8, -1000.24, 1, 0, 999};

	double			**G = create_identity_matrix(size);
	G[0][1] = proportions[0];
	G[0][2] = proportions[1];
	G[1][0] = proportions[2];
	G[1][2] = proportions[3];
	G[2][0] = proportions[4];
	G[2][1] = proportions[5];

	double			**shearing = create_shearing_matrix(proportions);
	int				result = are_equals_matrices(shearing, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&shearing);
	free_matrix(&G);
}

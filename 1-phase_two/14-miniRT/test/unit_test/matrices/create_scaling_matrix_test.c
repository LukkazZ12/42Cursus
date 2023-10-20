#include "unit_test.h"

Test(matrices, test_create_scaling_matrix) {
	int				size = 4;
	t_coordinates	tuple = {12.9, 33.8, -1000.24, 1};

	double			**G = create_identity_matrix(size);
	G[0][0] = tuple.x;
	G[1][1] = tuple.y;
	G[2][2] = tuple.z;

	double			**scaling = create_scaling_matrix(tuple);
	int				result = are_equals_matrices(scaling, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&scaling);
	free_matrix(&G);
}

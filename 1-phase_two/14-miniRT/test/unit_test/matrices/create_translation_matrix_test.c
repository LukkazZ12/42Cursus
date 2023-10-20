#include "unit_test.h"

Test(matrices, test_create_translation_matrix) {
	int				size = 4;
	t_coordinates	tuple = {12.9, 33.8, -1000.24, 1};

	double			**G = create_identity_matrix(size);
	G[0][3] = tuple.x;
	G[1][3] = tuple.y;
	G[2][3] = tuple.z;

	double			**translation = create_translation_matrix(tuple);
	int				result = are_equals_matrices(translation, G);

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
	free_matrix(&translation);
	free_matrix(&G);
}

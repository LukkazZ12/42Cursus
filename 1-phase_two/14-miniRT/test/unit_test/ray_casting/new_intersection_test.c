#include "unit_test.h"

Test(ray_casting, test_new_intersection_0) {
	t_sphere		*sphere = {0};
	t_intersections	*new = new_intersection(SP, 2, (void *)sphere);

	cr_assert(epsilon_eq(flt, SP, new->type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, new->t, EPSILON));
	free(new);
}

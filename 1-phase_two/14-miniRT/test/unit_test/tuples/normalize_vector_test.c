#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_normalize_vector_2_3_4_5) {
	t_coordinates	a = {.x = 2, .y = 3, .z = 4, .w = 5};
	t_coordinates	expected = {.x = 0.272165, .y = 0.408248, .z = 0.544331, .w = 0.680413};
	t_coordinates	result = normalize_vector(a);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

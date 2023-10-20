#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_negate_tuple_0_0_0_0) {
	t_coordinates	a = {.x = 0, .y = 0, .z = 0, .w = 0};
	t_coordinates	expected = {.x = 0, .y = 0, .z = 0, .w = 0};
	t_coordinates	result = negate_tuple(a);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

Test(tuples, test_negate_tuple_minus_1_3_point_14_7_1) {
	t_coordinates	a = {.x = -1, .y = 3.14, .z = 7, .w = 1};
	t_coordinates	expected = {.x = 1, .y = -3.14, .z = -7, .w = -1};
	t_coordinates	result = negate_tuple(a);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}
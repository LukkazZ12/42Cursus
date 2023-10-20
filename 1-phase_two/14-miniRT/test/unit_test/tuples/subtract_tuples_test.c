#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_subtract_tuples_0_0_0_0__0_0_0_0) {
	t_coordinates	a = {.x = 0, .y = 0, .z = 0, .w = 0}, b = {.x = 0, .y = 0, .z = 0, .w = 0};
	t_coordinates	expected = {.x = 0, .y = 0, .z = 0, .w = 0};
	t_coordinates	result = subtract_tuples(a, b);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

Test(tuples, test_subtract_tuples_1_2_point_5_0__0_minus_5_10_point_6_1) {
	t_coordinates	a = {.x = 0, .y = 1, .z = 2.5, .w = 0}, b = {.x = 0, .y = -5, .z = 10.6, .w = 1};
	t_coordinates	expected = {.x = 0, .y = 6, .z = -8.1, .w = -1};
	t_coordinates	result = subtract_tuples(a, b);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}
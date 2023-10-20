#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_multiply_tuple_3_point_5__1_minus_2_3_minus_4) {
	t_coordinates	a = {.x = 1, .y = -2, .z = 3, .w = -4};
	t_coordinates	expected = {.x = 3.5, .y = -7, .z = 10.5, .w = -14};
	t_coordinates	result = multiply_tuple(3.5, a);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

Test(tuples, test_multiply_tuple_0_point_5__1_minus_2_3_minus_4) {
	t_coordinates	a = {.x = 1, .y = -2, .z = 3, .w = -4};
	t_coordinates	expected = {.x = 0.5, .y = -1, .z = 1.5, .w = -2};
	t_coordinates	result = multiply_tuple(0.5, a);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}
#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_calculate_cross_product_1_0_0_0__0_1_0_0) {
	t_coordinates	a = {.x = 1, .y = 0, .z = 0, .w = 0}, b = {.x = 0, .y = 1, .z = 0, .w = 0};
	t_coordinates	expected = {.x = 0, .y = 0, .z = 1, .w = 0};
	t_coordinates	result = calculate_cross_product(a, b);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

Test(tuples, test_calculate_cross_product_0_1_0_0__0_0_1_0) {
	t_coordinates	a = {.x = 0, .y = 1, .z = 0, .w = 0}, b = {.x = 0, .y = 0, .z = 1, .w = 0};
	t_coordinates	expected = {.x = 1, .y = 0, .z = 0, .w = 0};
	t_coordinates	result = calculate_cross_product(a, b);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

Test(tuples, test_calculate_cross_product_0_0_1_0__1_0_0_0) {
	t_coordinates	a = {.x = 0, .y = 0, .z = 1, .w = 0}, b = {.x = 1, .y = 0, .z = 0, .w = 0};
	t_coordinates	expected = {.x = 0, .y = 1, .z = 0, .w = 0};
	t_coordinates	result = calculate_cross_product(a, b);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

Test(tuples, test_calculate_cross_product_1_2_3_0__2_3_4_0) {
	t_coordinates	a = {.x = 1, .y = 2, .z = 3, .w = 0}, b = {.x = 2, .y = 3, .z = 4, .w = 0};
	t_coordinates	expected = {.x = -1, .y = 2, .z = -1, .w = 0};
	t_coordinates	result = calculate_cross_product(a, b);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

Test(tuples, test_calculate_cross_product_2_3_4_0__1_2_3_0) {
	t_coordinates	a = {.x = 2, .y = 3, .z = 4, .w = 0}, b = {.x = 1, .y = 2, .z = 3, .w = 0};
	t_coordinates	expected = {.x = 1, .y = -2, .z = 1, .w = 0};
	t_coordinates	result = calculate_cross_product(a, b);

	cr_assert(epsilon_eq(flt, expected.x, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, expected.y, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, expected.z, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, expected.w, result.w, EPSILON));
}

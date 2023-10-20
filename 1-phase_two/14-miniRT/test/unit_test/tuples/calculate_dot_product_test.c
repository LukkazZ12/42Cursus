#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_calculate_dot_product_1_0_0_0__0_1_0_0) {
	t_coordinates	a = {.x = 1, .y = 0, .z = 0, .w = 0}, b = {.x = 0, .y = 1, .z = 0, .w = 0};
	double	result = calculate_dot_product(a, b);

	cr_assert(epsilon_eq(flt, 0, result, EPSILON));
}

Test(tuples, test_calculate_dot_product_2_13_point_6_minus_8_minus_7_point_5__0_point_555_minus_3_point_14_minus_1_2_point_44) {
	t_coordinates	a = {.x = 2, .y = 13.6, .z = -8, .w = -7.5}, b = {.x = 0.555, .y = -3.14, .z = -1, .w = 2.44};
	double	result = calculate_dot_product(a, b);

	cr_assert(epsilon_eq(flt, -51.894, result, EPSILON));
}

Test(tuples, test_calculate_dot_product_0_0_0_0__0_0_0_0) {
	t_coordinates	a = {.x = 0, .y = 0, .z = 0, .w = 0}, b = {.x = 0, .y = 0, .z = 0, .w = 0};
	double	result = calculate_dot_product(a, b);

	cr_assert(epsilon_eq(flt, 0, result, EPSILON));
}
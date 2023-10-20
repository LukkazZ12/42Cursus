#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_are_equals_tuples_0_0_0_0__0_0_0_0) {
	t_coordinates	a = {.x = 0, .y = 0, .z = 0, .w = 0}, b = {.x = 0, .y = 0, .z = 0, .w = 0};
	cr_assert(epsilon_eq(flt, 1, are_equals_tuples(a, b), EPSILON));
}

Test(tuples, test_are_equals_tuples_1_0_0_0__0_0_0_0) {
	t_coordinates	a = {.x = 1, .y = 0, .z = 0, .w = 0}, b = {.x = 0, .y = 0, .z = 0, .w = 0};
	cr_assert(epsilon_eq(flt, 0, are_equals_tuples(a, b), EPSILON));
}

Test(tuples, test_are_equals_tuples_0_345678_0_0_0__0_345679_0_0_0) {
	t_coordinates	a = {.x = 0.345678, .y = 0, .z = 0, .w = 0}, b = {.x = 0.345679, .y = 0, .z = 0, .w = 0};
	cr_assert(epsilon_eq(flt, 1, are_equals_tuples(a, b), EPSILON));
}

Test(tuples, test_are_equals_tuples_0_34568_0_0_0__0_34569_0_0_0) {
	t_coordinates	a = {.x = 0.34568, .y = 0, .z = 0, .w = 0}, b = {.x = 0.34569, .y = 0, .z = 0, .w = 0};
	cr_assert(epsilon_eq(flt, 0, are_equals_tuples(a, b), EPSILON));
}
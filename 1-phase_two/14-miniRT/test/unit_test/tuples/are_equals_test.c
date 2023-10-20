#include "criterion.h"
#include "new/assert.h"
#include "unit_test.h"
#include <sys/types.h>
#include <sys/wait.h>

Test(tuples, test_are_equals_0_0) {
	cr_assert(epsilon_eq(flt, 1, are_equals(0, 0), EPSILON));
}

Test(tuples, test_are_equals_1_0) {
	cr_assert(epsilon_eq(flt, 0, are_equals(1, 0), EPSILON));
}

Test(tuples, test_are_equals_0_345678_0_345679) {
	cr_assert(epsilon_eq(flt, 1, are_equals(0.345678, 0.345679), EPSILON));
}

Test(tuples, test_are_equals_0_34568_0_34569) {
	cr_assert(epsilon_eq(flt, 0, are_equals(0.34568, 0.34569), EPSILON));
}

Test(tuples, test_are_equals_minus_0_345678_minus_0_345679) {
	cr_assert(epsilon_eq(flt, 1, are_equals(-0.345678, -0.345679), EPSILON));
}

Test(tuples, test_are_equals_minus_0_34568_minus_0_34569) {
	cr_assert(epsilon_eq(flt, 0, are_equals(-0.34568, -0.34569), EPSILON));
}

Test(tuples, test_are_equals_0_345678_minus_0_345679) {
	cr_assert(epsilon_eq(flt, 0, are_equals(0.345678, -0.345679), EPSILON));
}

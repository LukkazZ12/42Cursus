#include "unit_test.h"

Test(parser, test_validate_normalized_vector_0_0_1) {
	t_coordinates	coordinates = {.x = 0, .y = 0, .z = 1};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_1_0_0) {
	t_coordinates	coordinates = {.x = 1, .y = 0, .z = 0};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_0_123456_0_789012_0_345678) {
	t_coordinates	coordinates = {.x = 0.123456, .y = 0.789012, .z = 0.345678};
	int		expected = 0;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_0_0_minus_1) {
	t_coordinates	coordinates = {.x = 0, .y = 0, .z = -1};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_0_577350_0_577350_0_577350) {
	t_coordinates	coordinates = {.x = 0.577350, .y = 0.577350, .z = 0.577350};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_minus_0_707107_0_0_707107) {
	t_coordinates	coordinates = {.x = -0.707107, .y = 0, .z = 0.707107};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_0_267261_minus_0_534522_0_801784) {
	t_coordinates	coordinates = {.x = 0.267261, .y = -0.534522, .z = 0.801784};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_minus_0_267261_0_534522_minus_0_801784) {
	t_coordinates	coordinates = {.x = -0.267261, .y = 0.534522, .z = -0.801784};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_0_408248_minus_0_816497_0_408248) {
	t_coordinates	coordinates = {.x = 0.408248, .y = -0.816497, .z = 0.408248};
	int		expected = 1;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_2_0_0) {
	t_coordinates	coordinates = {.x = 2, .y = 0, .z = 0};
	int		expected = 0;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_normalized_vector_0_0_0) {
	t_coordinates	coordinates = {.x = 0, .y = 0, .z = 0};
	int		expected = 0;
	int		result;

	result = validate_normalized_vector(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

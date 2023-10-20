#include "unit_test.h"

Test(parser, test_validate_double_empty_null) {
	char	*number = NULL;
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_empty_string) {
	char	*number = "";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_plus) {
	char	*number = "+";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_minus) {
	char	*number = "-";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_space) {
	char	*number = " ";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_plus_minus) {
	char	*number = "+-";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_plus_point) {
	char	*number = "+.";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_plus_point_fifty) {
	char	*number = "+.50";
	int		expected = 1;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_plus_point_fifty_point) {
	char	*number = "+.50.";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_letter) {
	char	*number = "f";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_fifty_point_eight) {
	char	*number = "50.8";
	int		expected = 1;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_fifty_point_point) {
	char	*number = "50..";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_fifty_point_point_eight) {
	char	*number = "50..8";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_point_fifty_eight) {
	char	*number = ".58";
	int		expected = 1;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_point) {
	char	*number = ".";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_fifty_point) {
	char	*number = "50.";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_fifty_letter) {
	char	*number = "50l";
	int		expected = 0;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_one) {
	char	*number = "1";
	int		expected = 1;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_one_thousand_five_hundred_twenty_one) {
	char	*number = "1521";
	int		expected = 1;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_double_one_point_two) {
	char	*number = "1.2";
	int		expected = 1;
	int		result;

	result = validate_double(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

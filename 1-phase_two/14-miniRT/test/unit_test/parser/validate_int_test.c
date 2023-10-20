#include "unit_test.h"

Test(parser, test_validate_int_null) {
	char	*color = NULL;
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_empty) {
	char	*color = "";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_plus) {
	char	*color = "+";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_space) {
	char	*color = " ";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_letter) {
	char	*color = "f";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_forty_two) {
	char	*color = "42";
	double	expected = 1;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_plus_forty_two) {
	char	*color = "+42";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_minus_forty_two) {
	char	*color = "-42";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_four_point_two) {
	char	*color = "4.2";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_validate_int_four_thousand_two_hundred) {
	char	*color = "4200";
	double	expected = 0;
	double	result;

	result = validate_int(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

#include "unit_test.h"

Test(parser, test_validate_angle_null) {
	char	*angle = NULL;
	int		expected = 0;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_empty) {
	char	*angle = "";
	int		expected = 0;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_letter) {
	char	*angle = "a";
	int		expected = 0;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_space) {
	char	*angle = " ";
	int		expected = 0;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_double) {
	char	*angle = "10.6";
	int		expected = 0;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_ten) {
	char	*angle = "10";
	int		expected = 1;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_minus_ten) {
	char	*angle = "-10";
	int		expected = 0;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_zero) {
	char	*angle = "0";
	int		expected = 1;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_180) {
	char	*angle = "180";
	int		expected = 1;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

Test(parser, test_validate_angle_181) {
	char	*angle = "181";
	int		expected = 0;
	int		result;

	result = validate_angle(angle);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
}

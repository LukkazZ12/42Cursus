#include "unit_test.h"

Test(parser, test_atod_fifty_point_eight) {
	char	*number = "50.8";
	double	expected = 50.8;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_one_point_two) {
	char	*number = "1.2";
	double	expected = 1.2;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_zero) {
	char	*number = "0";
	double	expected = 0;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_plus_zero) {
	char	*number = "+0";
	double	expected = 0;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_minus_zero) {
	char	*number = "-0";
	double	expected = 0;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_plus_zero_point_three) {
	char	*number = "+0.3";
	double	expected = 0.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_minus_zero_point_three) {
	char	*number = "-0.3";
	double	expected = -0.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_plus_point_three) {
	char	*number = "+.3";
	double	expected = 0.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_minus_point_three) {
	char	*number = "-.3";
	double	expected = -0.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_plus_one_point_three) {
	char	*number = "+1.3";
	double	expected = 1.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_minus_one_point_three) {
	char	*number = "-1.3";
	double	expected = -1.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_one_point_three) {
	char	*number = "1.3";
	double	expected = 1.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_plus_one_hundred_fifty_eight_point_three) {
	char	*number = "+158.3";
	double	expected = 158.3;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_minus_one_hundred_fifty_eight_point_3579512) {
	char	*number = "-158.3579512";
	double	expected = -158.3579512;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

Test(parser, test_atod_minus_one_hundred_fifty_eight_point_35795128) {
	char	*number = "-158.35795128";
	double	expected = -158.35795128;
	double	result;

	result = ft_atod(number);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

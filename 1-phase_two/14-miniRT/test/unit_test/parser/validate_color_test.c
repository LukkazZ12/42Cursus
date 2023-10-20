#include "unit_test.h"

Test(parser, test_validate_color_null) {
	char	**color = NULL;
	int		expected = 0;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
	free_ptrptr(&color);
}

Test(parser, test_validate_color_empty) {
	char	**color = (char **)ft_calloc(2, sizeof(char *));
	color[0] = ft_strdup("");
	int		expected = 0;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
	free_ptrptr(&color);
}

Test(parser, test_validate_color_empty_empty) {
	char	**color = (char **)ft_calloc(3, sizeof(char *));
	color[0] = ft_strdup("");
	color[1] = ft_strdup("");
	int		expected = 0;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&color);
}

Test(parser, test_validate_color_space) {
	char	**color = (char **)ft_calloc(2, sizeof(char *));
	color[0] = ft_strdup(" ");
	int		expected = 0;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&color);
}

Test(parser, test_validate_color_letter) {
	char	**color = (char **)ft_calloc(2, sizeof(char *));
	color[0] = ft_strdup("f");
	int		expected = 0;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&color);
}

Test(parser, test_validate_color_255_25_5) {
	char	**color = (char **)ft_calloc(4, sizeof(char *));
	color[0] = ft_strdup("255");
	color[1] = ft_strdup("25");
	color[2] = ft_strdup("5");
	int		expected = 1;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&color);
}

Test(parser, test_validate_color_256_25_5) {
	char	**color = (char **)ft_calloc(4, sizeof(char *));
	color[0] = ft_strdup("256");
	color[1] = ft_strdup("25");
	color[2] = ft_strdup("5");
	int		expected = 0;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&color);
}

Test(parser, test_validate_color_minus_255_25_5) {
	char	**color = (char **)ft_calloc(4, sizeof(char *));
	color[0] = ft_strdup("-255");
	color[1] = ft_strdup("25");
	color[2] = ft_strdup("5");
	int		expected = 0;
	int		result;

	result = validate_color(color);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&color);
}

Test(parser, test_validate_color_255_25_5_45) {
	char	**color = (char **)ft_calloc(5, sizeof(char *));
	color[0] = ft_strdup("255");
	color[1] = ft_strdup("25");
	color[2] = ft_strdup("5");
	color[3] = ft_strdup("45");
	int		expected = 0;
	int		result;

	result = validate_color(color);

	free_ptrptr(&color);
	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

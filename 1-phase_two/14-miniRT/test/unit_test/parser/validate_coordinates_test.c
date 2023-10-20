#include "unit_test.h"

Test(parser, test_validate_coordinates_null) {
	char	**coordinates = NULL;
	int		expected = 0;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_empty) {
	char	**coordinates = (char **)ft_calloc(2, sizeof(char *));
	coordinates[0] = ft_strdup("");
	int		expected = 0;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON)); 
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_empty_empty) {
	char	**coordinates = (char **)ft_calloc(3, sizeof(char *));
	coordinates[0] = ft_strdup("");
	coordinates[1] = ft_strdup("");
	int		expected = 0;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_space) {
	char	**coordinates = (char **)ft_calloc(2, sizeof(char *));
	coordinates[0] = ft_strdup(" ");
	int		expected = 0;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_letter) {
	char	**coordinates = (char **)ft_calloc(2, sizeof(char *));
	coordinates[0] = ft_strdup("f");
	int		expected = 0;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_255_25_5) {
	char	**coordinates = (char **)ft_calloc(4, sizeof(char *));
	coordinates[0] = ft_strdup("0");
	coordinates[1] = ft_strdup("0");
	coordinates[2] = ft_strdup("1");
	int		expected = 1;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_256_25_5) {
	char	**coordinates = (char **)ft_calloc(4, sizeof(char *));
	coordinates[0] = ft_strdup("256");
	coordinates[1] = ft_strdup("25");
	coordinates[2] = ft_strdup("5");
	int		expected = 1;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_minus_255_25_5) {
	char	**coordinates = (char **)ft_calloc(4, sizeof(char *));
	coordinates[0] = ft_strdup("-255");
	coordinates[1] = ft_strdup("25");
	coordinates[2] = ft_strdup("5");
	int		expected = 1;
	int		result;

	result = validate_coordinates(coordinates);

	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
	free_ptrptr(&coordinates);
}

Test(parser, test_validate_coordinates_255_25_5_45) {
	char	**coordinates = (char **)ft_calloc(5, sizeof(char *));
	coordinates[0] = ft_strdup("255");
	coordinates[1] = ft_strdup("25");
	coordinates[2] = ft_strdup("5");
	coordinates[3] = ft_strdup("45");
	int		expected = 0;
	int		result;

	result = validate_coordinates(coordinates);

	free_ptrptr(&coordinates);
	cr_assert(epsilon_eq(flt, expected, result, EPSILON));
}

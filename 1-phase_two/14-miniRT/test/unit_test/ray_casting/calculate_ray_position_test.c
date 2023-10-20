#include "unit_test.h"

Test(ray_casting, test_calculate_ray_position_0) {
	t_ray	ray = {{0, 0, 1, 1}, {0, 0, -1, 0}};
	double	t = 0;

	t_coordinates	ray_position = calculate_ray_position(ray, t);

	int				result = are_equals_tuples(ray_position, (t_coordinates){0, 0, 1, 1});

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
}

Test(ray_casting, test_calculate_ray_position_2) {
	t_ray	ray = {{0, 0, 1, 1}, {0, 0, -1, 0}};
	double	t = 2;

	t_coordinates	ray_position = calculate_ray_position(ray, t);

	int				result = are_equals_tuples(ray_position, (t_coordinates){0, 0, -1, 1});

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
}

Test(ray_casting, test_calculate_ray_position_4_point_55) {
	t_ray	ray = {{3.5, -2, 2.999, 1}, {3.6, -6.5, -10.98, 0}};
	double	t = 4.55;

	t_coordinates	ray_position = calculate_ray_position(ray, t);

	int				result = are_equals_tuples(ray_position, (t_coordinates){19.88, -31.575, -46.96, 1});

	cr_assert(epsilon_eq(flt, 1, result, EPSILON));
}

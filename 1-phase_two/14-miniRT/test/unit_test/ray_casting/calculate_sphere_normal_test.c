#include "unit_test.h"

Test(ray_casting, test_calculate_sphere_normal_0) {
	t_rt		*rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->spheres = (t_sphere *)ft_calloc(2, sizeof(t_sphere));
	rt->spheres[0] = (t_sphere){{0, 0, 0, 1}, 2, {0, 0, 0}};
	t_ray		ray = {{0, 0, -5, 1}, {0, 0, 1, 0}};
	rt->num_sp = 1;

	intersections(rt, ray);

	t_intersections	*hit = get_hit(rt->intersections);
	t_coordinates	result = calculate_sphere_normal(hit);

	cr_assert(epsilon_eq(flt, 0, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, -1, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.w, EPSILON));
	free_intersections(&rt->intersections);
	free(rt->spheres);
	free(rt);
}

Test(ray_casting, test_calculate_sphere_normal_1) {
	t_rt		*rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->spheres = (t_sphere *)ft_calloc(2, sizeof(t_sphere));
	rt->spheres[0] = (t_sphere){{0, 0, 0, 1}, 4, {0, 0, 0}};
	t_ray		ray = {{0, 0, -5, 1}, {0, 0, 1, 0}};
	rt->num_sp = 1;

	intersections(rt, ray);

	t_intersections	*hit = get_hit(rt->intersections);
	t_coordinates	result = calculate_sphere_normal(hit);

	cr_assert(epsilon_eq(flt, 0, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, -1, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.w, EPSILON));
	free_intersections(&rt->intersections);
	free(rt->spheres);
	free(rt);
}

Test(ray_casting, test_calculate_sphere_normal_2) {
	t_rt		*rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->spheres = (t_sphere *)ft_calloc(2, sizeof(t_sphere));
	rt->spheres[0] = (t_sphere){{0, 1, 0, 1}, 2, {0, 0, 0}};
	t_ray		ray = {{0, 0, -5, 1}, {0, 0, 1, 0}};
	rt->num_sp = 1;

	intersections(rt, ray);

	t_intersections	*hit = get_hit(rt->intersections);
	t_coordinates	result = calculate_sphere_normal(hit);

	cr_assert(epsilon_eq(flt, 0, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, -1, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.w, EPSILON));
	free_intersections(&rt->intersections);
	free(rt->spheres);
	free(rt);
}

Test(ray_casting, test_calculate_sphere_normal_3) {
	t_rt		*rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->spheres = (t_sphere *)ft_calloc(2, sizeof(t_sphere));
	rt->spheres[0] = (t_sphere){{3, 4, 0, 1}, 4, {0, 0, 0}};
	t_ray		ray = {{-3, -4, 0, 1}, {0.6, 0.8, 0, 0}};
	rt->num_sp = 1;

	intersections(rt, ray);

	t_intersections	*hit = get_hit(rt->intersections);
	t_coordinates	result = calculate_sphere_normal(hit);

	cr_assert(epsilon_eq(flt, -0.6, result.x, EPSILON));
	cr_assert(epsilon_eq(flt, -0.8, result.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result.w, EPSILON));
	free_intersections(&rt->intersections);
	free(rt->spheres);
	free(rt);
}

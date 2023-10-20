#include "unit_test.h"

Test(ray_casting, test_calculate_ray_sphere_intersections_0) {
	t_sphere	sphere = {{0, 0, 0, 1}, 2, {0, 0, 0}};
	t_ray	ray = {{0, 0, -5, 1}, {0, 0, 1, 0}};

	t_intersection	intersection = calculate_ray_sphere_intersections(ray, &sphere);

	cr_assert(epsilon_eq(flt, SP, intersection.type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersection.count, EPSILON));
	cr_assert(epsilon_eq(flt, 4, intersection.t[0], EPSILON));
	cr_assert(epsilon_eq(flt, 6, intersection.t[1], EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].y, EPSILON));
	cr_assert(epsilon_eq(flt, -1, intersection.hit_point[0].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[0].w, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].y, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[1].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[1].w, EPSILON));
}

Test(ray_casting, test_calculate_ray_sphere_intersections_1) {
	t_sphere	sphere = {{0, 0, 0, 1}, 2, {0, 0, 0}};
	t_ray	ray = {{0, 1, -5, 1}, {0, 0, 1, 0}};

	t_intersection	intersection = calculate_ray_sphere_intersections(ray, &sphere);

	cr_assert(epsilon_eq(flt, SP, intersection.type, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.count, EPSILON));
	cr_assert(epsilon_eq(flt, 5, intersection.t[0], EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].x, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[0].y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[0].w, EPSILON));
}

Test(ray_casting, test_calculate_ray_sphere_intersections_2) {
	t_sphere	sphere = {{0, 0, 0, 1}, 2, {0, 0, 0}};
	t_ray	ray = {{0, 0, 0, 1}, {0, 0, 1, 0}};

	t_intersection	intersection = calculate_ray_sphere_intersections(ray, &sphere);

	cr_assert(epsilon_eq(flt, SP, intersection.type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersection.count, EPSILON));
	cr_assert(epsilon_eq(flt, -1, intersection.t[0], EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.t[1], EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].y, EPSILON));
	cr_assert(epsilon_eq(flt, -1, intersection.hit_point[0].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[0].w, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].y, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[1].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[1].w, EPSILON));
}

Test(ray_casting, test_calculate_ray_sphere_intersections_3) {
	t_sphere	sphere = {{0, 0, 0, 1}, 2, {0, 0, 0}};
	t_ray	ray = {{0, 0, 2, 1}, {0, 0, 1, 0}};

	t_intersection	intersection = calculate_ray_sphere_intersections(ray, &sphere);

	cr_assert(epsilon_eq(flt, SP, intersection.type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersection.count, EPSILON));
	cr_assert(epsilon_eq(flt, -3, intersection.t[0], EPSILON));
	cr_assert(epsilon_eq(flt, -1, intersection.t[1], EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].y, EPSILON));
	cr_assert(epsilon_eq(flt, -1, intersection.hit_point[0].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[0].w, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].y, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[1].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[1].w, EPSILON));
}

Test(ray_casting, test_calculate_ray_sphere_intersections_4) {
	t_sphere	sphere = {{0, 0, 0, 1}, 2, {0, 0, 0}};
	t_ray	ray = {{0, 2, 0, 1}, {0, 0, 1, 0}};

	t_intersection	intersection = calculate_ray_sphere_intersections(ray, &sphere);

	cr_assert(epsilon_eq(flt, SP, intersection.type, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.count, EPSILON));
}

Test(ray_casting, test_calculate_ray_sphere_intersections_5) {
	t_sphere	sphere = {{0, 0, 0, 1}, 4, {0, 0, 0}};
	t_ray	ray = {{0, 0, -5, 1}, {0, 0, 1, 0}};

	t_intersection	intersection = calculate_ray_sphere_intersections(ray, &sphere);

	cr_assert(epsilon_eq(flt, SP, intersection.type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersection.count, EPSILON));
	cr_assert(epsilon_eq(flt, 3, intersection.t[0], EPSILON));
	cr_assert(epsilon_eq(flt, 7, intersection.t[1], EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[0].y, EPSILON));
	cr_assert(epsilon_eq(flt, -2, intersection.hit_point[0].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[0].w, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersection.hit_point[1].y, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersection.hit_point[1].z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, intersection.hit_point[1].w, EPSILON));
}

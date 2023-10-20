#include "unit_test.h"

Test(ray_casting, test_intersections_0) {
	t_ray		ray = {{0, 0, -5, 1}, {0, 0, 1, 0}};
	t_rt		*rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->spheres = (t_sphere *)ft_calloc(4, sizeof(t_sphere));
	rt->num_sp = 3;
	rt->spheres[0].point.x = 0;
	rt->spheres[0].point.y = 0;
	rt->spheres[0].point.z = 0;
	rt->spheres[0].point.w = 1;
	rt->spheres[0].diameter = 2;
	rt->spheres[1].point.x = 0;
	rt->spheres[1].point.y = 0;
	rt->spheres[1].point.z = 3;
	rt->spheres[1].point.w = 1;
	rt->spheres[1].diameter = 4;
	rt->spheres[2].point.x = 0;
	rt->spheres[2].point.y = 0;
	rt->spheres[2].point.z = 6;
	rt->spheres[2].point.w = 1;
	rt->spheres[2].diameter = 7.5;
	
	intersections(rt, ray);

	cr_assert(epsilon_eq(flt, SP, rt->intersections->object, EPSILON));
	cr_assert(epsilon_eq(flt, 4, rt->intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 6, rt->intersections->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 6, rt->intersections->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 7.25, rt->intersections->next->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 10, rt->intersections->next->next->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->next->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 14.75, rt->intersections->next->next->next->next->next->t, EPSILON));
	free_intersections(&rt->intersections);
	free(rt->spheres);
	free(rt);
}

Test(ray_casting, test_intersections_1) {
	t_ray		ray = {{-5, 0, 0, 1}, {1, 0, 0, 0}};
	t_rt		*rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->spheres = (t_sphere *)ft_calloc(4, sizeof(t_sphere));
	rt->num_sp = 3;
	rt->spheres[0].point.x = 0;
	rt->spheres[0].point.y = 0;
	rt->spheres[0].point.z = 0;
	rt->spheres[0].point.w = 1;
	rt->spheres[0].diameter = 2;
	rt->spheres[1].point.x = 3;
	rt->spheres[1].point.y = 0;
	rt->spheres[1].point.z = 0;
	rt->spheres[1].point.w = 1;
	rt->spheres[1].diameter = 4;
	rt->spheres[2].point.x = 6;
	rt->spheres[2].point.y = 0;
	rt->spheres[2].point.z = 0;
	rt->spheres[2].point.w = 1;
	rt->spheres[2].diameter = 7.5;
	
	intersections(rt, ray);

	cr_assert(epsilon_eq(flt, SP, rt->intersections->object, EPSILON));
	cr_assert(epsilon_eq(flt, 4, rt->intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 6, rt->intersections->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 6, rt->intersections->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 7.25, rt->intersections->next->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 10, rt->intersections->next->next->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->next->next->next->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 14.75, rt->intersections->next->next->next->next->next->t, EPSILON));
	free_intersections(&rt->intersections);
	free(rt->spheres);
	free(rt);
}

Test(ray_casting, test_intersections_2) {
	t_ray		ray = {{-3, -4, 0, 1}, {0.6, 0.8, 0, 0}};
	t_rt		*rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->spheres = (t_sphere *)ft_calloc(4, sizeof(t_sphere));
	rt->num_sp = 1;
	rt->spheres[0].point.x = 3;
	rt->spheres[0].point.y = 4;
	rt->spheres[0].point.z = 0;
	rt->spheres[0].point.w = 1;
	rt->spheres[0].diameter = 4;
	
	intersections(rt, ray);

	cr_assert(epsilon_eq(flt, SP, rt->intersections->object, EPSILON));
	cr_assert(epsilon_eq(flt, 8, rt->intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, SP, rt->intersections->next->object, EPSILON));
	cr_assert(epsilon_eq(flt, 12, rt->intersections->next->t, EPSILON));
	free_intersections(&rt->intersections);
	free(rt->spheres);
	free(rt);
}

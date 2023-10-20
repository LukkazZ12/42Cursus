#include "unit_test.h"

Test(ray_casting, test_get_hit_0) {
	t_intersections	*intersections = NULL;
	t_sphere		*sphere1 = ft_calloc(1, sizeof(t_sphere));
	sphere1->color = (t_color){50, 0, 0};
	t_sphere		*sphere2 = ft_calloc(1, sizeof(t_sphere));
	sphere2->color = (t_color){10, 60, 20};
	t_intersections	*new = new_intersection(SP, 2, (void *)sphere1);
	t_intersections	*new2 = new_intersection(SP, -2, (void *)sphere2);

	intersections_list_add(&intersections, new);
	intersections_list_add(&intersections, new2);

	t_intersections	*result = get_hit(intersections);

	cr_assert(epsilon_eq(flt, 2, result->t, EPSILON));
	cr_assert(epsilon_eq(flt, 50, result->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, result->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere1);
	free(sphere2);
}

Test(ray_casting, test_get_hit_1) {
	t_intersections	*intersections = NULL;
	t_sphere		*sphere1 = ft_calloc(1, sizeof(t_sphere));
	sphere1->color = (t_color){50, 0, 0};
	t_sphere		*sphere2 = ft_calloc(1, sizeof(t_sphere));
	sphere2->color = (t_color){10, 60, 20};
	t_sphere		*sphere3 = ft_calloc(1, sizeof(t_sphere));
	sphere3->color = (t_color){0, 0, 0};
	t_sphere		*sphere4 = ft_calloc(1, sizeof(t_sphere));
	sphere4->color = (t_color){2, 2, 2};
	t_sphere		*sphere5 = ft_calloc(1, sizeof(t_sphere));
	sphere5->color = (t_color){30, 60, 90};
	t_intersections	*new = new_intersection(SP, 2, (void *)sphere1);
	t_intersections	*new2 = new_intersection(SP, -2, (void *)sphere2);
	t_intersections	*new3 = new_intersection(SP, -52, (void *)sphere3);
	t_intersections	*new4 = new_intersection(SP, 36, (void *)sphere4);
	t_intersections	*new5 = new_intersection(SP, 0.95, (void *)sphere5);

	intersections_list_add(&intersections, new);
	intersections_list_add(&intersections, new2);
	intersections_list_add(&intersections, new3);
	intersections_list_add(&intersections, new4);
	intersections_list_add(&intersections, new5);

	t_intersections	*result = get_hit(intersections);

	cr_assert(epsilon_eq(flt, 0.95, result->t, EPSILON));
	cr_assert(epsilon_eq(flt, 30, result->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 60, result->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 90, result->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere1);
	free(sphere2);
	free(sphere3);
	free(sphere4);
	free(sphere5);
}

Test(ray_casting, test_get_hit_2) {
	t_intersections	*intersections = NULL;

	t_intersections	*result = get_hit(intersections);
	int	i;
	i = 1;
	if (!result)
		i = 0;

	cr_assert(epsilon_eq(flt, 0, i, EPSILON));
	free_intersections(&intersections);
}

#include "unit_test.h"

Test(ray_casting, test_intersections_list_add_0) {
	t_intersections	*intersections = NULL;
	t_sphere		*sphere = ft_calloc(1, sizeof(t_sphere));
	sphere->color = (t_color){0, 255, 0};
	t_intersections	*new = new_intersection(SP, 2, (void *)sphere);

	intersections_list_add(&intersections, new);

	cr_assert(epsilon_eq(flt, SP, intersections->type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 255, intersections->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere);
}

Test(ray_casting, test_intersections_list_add_1_0) {
	t_intersections	*intersections = NULL;
	t_sphere		*sphere1 = ft_calloc(1, sizeof(t_sphere));
	sphere1->color = (t_color){10, 60, 20};
	t_sphere		*sphere2 = ft_calloc(1, sizeof(t_sphere));
	sphere2->color = (t_color){50, 0, 0};
	t_intersections	*new = new_intersection(SP, 2, (void *)sphere1);
	t_intersections	*new2 = new_intersection(SP, 5, (void *)sphere2);

	intersections_list_add(&intersections, new);
	intersections_list_add(&intersections, new2);

	cr_assert(epsilon_eq(flt, SP, intersections->type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, 10, intersections->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 60, intersections->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 20, intersections->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 5, intersections->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 50, intersections->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere1);
	free(sphere2);
}

Test(ray_casting, test_intersections_list_add_1_1) {
	t_intersections	*intersections = NULL;
	t_sphere		*sphere1 = ft_calloc(1, sizeof(t_sphere));
	sphere1->color = (t_color){50, 0, 0};
	t_sphere		*sphere2 = ft_calloc(1, sizeof(t_sphere));
	sphere2->color = (t_color){10, 60, 20};
	t_intersections	*new = new_intersection(SP, 5, (void *)sphere1);
	t_intersections	*new2 = new_intersection(SP, 2, (void *)sphere2);

	intersections_list_add(&intersections, new);
	intersections_list_add(&intersections, new2);

	cr_assert(epsilon_eq(flt, SP, intersections->type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, 10, intersections->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 60, intersections->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 20, intersections->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 5, intersections->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 50, intersections->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere1);
	free(sphere2);
}

Test(ray_casting, test_intersections_list_add_2) {
	t_intersections	*intersections = NULL;
	t_sphere		*sphere1 = ft_calloc(1, sizeof(t_sphere));
	sphere1->color = (t_color){50, 0, 0};
	t_sphere		*sphere2 = ft_calloc(1, sizeof(t_sphere));
	sphere2->color = (t_color){10, 60, 20};
	t_sphere		*sphere3 = ft_calloc(1, sizeof(t_sphere));
	sphere3->color = (t_color){0, 0, 0};
	t_intersections	*new = new_intersection(SP, 2, (void *)sphere1);
	t_intersections	*new2 = new_intersection(SP, 5, (void *)sphere2);
	t_intersections	*new3 = new_intersection(SP, 3, (void *)sphere3);

	intersections_list_add(&intersections, new);
	intersections_list_add(&intersections, new2);
	intersections_list_add(&intersections, new3);

	cr_assert(epsilon_eq(flt, SP, intersections->type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, 50, intersections->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 3, intersections->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 5, intersections->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 10, intersections->next->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 60, intersections->next->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 20, intersections->next->next->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere1);
	free(sphere2);
	free(sphere3);
}

Test(ray_casting, test_intersections_list_add_3) {
	t_intersections	*intersections = NULL;
	t_sphere		*sphere1 = ft_calloc(1, sizeof(t_sphere));
	sphere1->color = (t_color){50, 0, 0};
	t_sphere		*sphere2 = ft_calloc(1, sizeof(t_sphere));
	sphere2->color = (t_color){10, 60, 20};
	t_sphere		*sphere3 = ft_calloc(1, sizeof(t_sphere));
	sphere3->color = (t_color){0, 0, 0};
	t_intersections	*new = new_intersection(SP, 2, (void *)sphere1);
	t_intersections	*new2 = new_intersection(SP, 3, (void *)sphere2);
	t_intersections	*new3 = new_intersection(SP, 5, (void *)sphere3);

	intersections_list_add(&intersections, new);
	intersections_list_add(&intersections, new2);
	intersections_list_add(&intersections, new3);

	cr_assert(epsilon_eq(flt, SP, intersections->type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, 50, intersections->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 3, intersections->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 10, intersections->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 60, intersections->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 20, intersections->next->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 5, intersections->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere1);
	free(sphere2);
	free(sphere3);
}

Test(ray_casting, test_intersections_list_add_4) {
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
	t_intersections	*new = new_intersection(SP, 5, (void *)sphere1);
	t_intersections	*new2 = new_intersection(SP, -6.96, (void *)sphere2);
	t_intersections	*new3 = new_intersection(SP, 2, (void *)sphere3);
	t_intersections	*new4 = new_intersection(SP, 0, (void *)sphere4);
	t_intersections	*new5 = new_intersection(SP, -10, (void *)sphere5);

	intersections_list_add(&intersections, new);
	intersections_list_add(&intersections, new2);
	intersections_list_add(&intersections, new3);
	intersections_list_add(&intersections, new4);
	intersections_list_add(&intersections, new5);

	cr_assert(epsilon_eq(flt, SP, intersections->type, EPSILON));
	cr_assert(epsilon_eq(flt, -10, intersections->t, EPSILON));
	cr_assert(epsilon_eq(flt, 30, intersections->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 60, intersections->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 90, intersections->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, -6.96, intersections->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 10, intersections->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 60, intersections->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 20, intersections->next->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->next->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->next->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->next->next->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->next->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 2, intersections->next->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->next->sphere->color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, SP, intersections->next->next->next->next->type, EPSILON));
	cr_assert(epsilon_eq(flt, 5, intersections->next->next->next->next->t, EPSILON));
	cr_assert(epsilon_eq(flt, 50, intersections->next->next->next->next->sphere->color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->next->next->sphere->color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, intersections->next->next->next->next->sphere->color.blue, EPSILON));
	free_intersections(&intersections);
	free(sphere1);
	free(sphere2);
	free(sphere3);
	free(sphere4);
	free(sphere5);
}

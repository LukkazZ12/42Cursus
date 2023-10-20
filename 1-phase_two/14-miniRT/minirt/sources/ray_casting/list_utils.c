/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:20:58 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/02 15:16:41 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	*new_intersection(t_intersection new, \
					int i, t_ray ray)
{
	t_intersections	*head;

	head = (t_intersections *)ft_calloc(1, sizeof(t_intersections));
	if (head == NULL)
		return (NULL);
	head->type = new.type;
	head->t = new.t[i];
	head->hit_point = new.hit_point[i];
	head->eye_vector = negate_tuple(ray.vector);
	if (new.type == SP)
		head->sphere = new.sphere;
	else if (new.type == PL)
		head->plane = new.plane;
	else
		head->cylinder = new.cylinder;
	calculate_normal(head);
	if (calculate_dot_product(head->eye_vector, head->normal) < 0)
		head->normal = negate_tuple(head->normal);
	head->over_point = add_tuples(head->hit_point, \
		multiply_tuple(EPSILON, head->normal));
	head->next = NULL;
	return (head);
}

static t_intersections	*get_intersections_position(t_intersections \
							*intersections, t_intersections *new)
{
	if (intersections == NULL)
		return (intersections);
	while (intersections->next)
	{
		if (intersections->next->t > new->t)
			return (intersections);
		intersections = intersections->next;
	}
	return (intersections);
}

void	intersections_list_add(t_intersections **intersections, \
			t_intersections *new)
{
	t_intersections	*aux;
	t_intersections	*aux_next;

	if (!(*intersections))
	{
		*intersections = new;
		return ;
	}
	if ((*intersections)->t > new->t)
	{
		aux = *intersections;
		new->next = aux;
		*intersections = new;
		return ;
	}
	aux = get_intersections_position(*intersections, new);
	aux_next = aux->next;
	aux->next = new;
	new->next = aux_next;
}

void	free_intersections(t_intersections **intersections)
{
	t_intersections	*aux;

	while (*intersections)
	{
		aux = (*intersections)->next;
		free(*intersections);
		*intersections = NULL;
		(*intersections) = aux;
	}
}

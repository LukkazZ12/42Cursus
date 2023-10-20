/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_ray_cone_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:42:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/03 17:41:13 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	check_cap(t_ray ray, double t)
{
	double	x;
	double	y;
	double	z;
	double	point;

	x = ray.point.x + t * ray.vector.x;
	y = ray.point.y + t * ray.vector.y;
	z = ray.point.z + t * ray.vector.z;
	point = x * x + z * z;
	if (point <= y * y + EPSILON)
		return (1);
	return (0);
}

static void	calculate_intersect_caps(t_ray ray_in, t_ray ray, \
			t_cone *cone, t_intersection *inter)
{
	double	t;

	if (are_equals(ray.vector.y, 0))
		return ;
	t = (cone->min - ray.point.y) / ray.vector.y;
	if (check_cap(ray, t))
	{
		inter->hit_point[inter->count] = calculate_ray_position(ray_in, t);
		inter->t[inter->count] = t;
		inter->count++;
	}
	t = (cone->max - ray.point.y) / ray.vector.y;
	if (check_cap(ray, t))
	{
		inter->hit_point[inter->count] = calculate_ray_position(ray_in, t);
		inter->t[inter->count] = t;
		inter->count++;
	}
}

t_intersection	calculate_ray_cone_intersections(t_ray ray_in, \
					t_cone *cone)
{
	int				i;
	double			y;
	t_intersection	inter;
	t_discriminant	disc;
	t_ray			ray;

	ray = transform_ray(ray_in, cone->inverse);
	inter = (t_intersection){CO, 0, .cone = cone};
	disc = calculate_discriminant_ray_cone(ray);
	if (disc.discriminant >= -EPSILON)
	{
		i = -1;
		while (++i < 2)
		{
			y = ray.point.y + disc.t[i] * ray.vector.y;
			if (y > cone->min && y < cone->max)
			{
				inter.t[inter.count] = disc.t[i];
				inter.hit_point[inter.count++] \
					= calculate_ray_position(ray_in, inter.t[i]);
			}
		}
	}
	calculate_intersect_caps(ray_in, ray, cone, &inter);
	return (inter);
}

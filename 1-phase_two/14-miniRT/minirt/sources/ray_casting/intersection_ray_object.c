/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_ray_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:11:39 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/03 17:35:13 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	calculate_ray_sphere_intersections(t_ray ray_in, \
					t_sphere *sphere)
{
	t_intersection	inter;
	t_discriminant	disc;
	t_ray			ray;

	ray = transform_ray(ray_in, sphere->inverse);
	inter = (t_intersection){SP, 0, .sphere = sphere};
	disc = calculate_discriminant_ray_sphere(ray);
	if (disc.discriminant < 0)
		return (inter);
	if (are_equals(disc.discriminant, 0))
	{
		inter.count = 1;
		inter.t[0] = disc.t[0];
		inter.hit_point[0] = calculate_ray_position(ray_in, inter.t[0]);
	}
	else
	{
		inter.count = 2;
		inter.t[0] = disc.t[0];
		inter.t[1] = disc.t[1];
		inter.hit_point[0] = calculate_ray_position(ray_in, inter.t[0]);
		inter.hit_point[1] = calculate_ray_position(ray_in, inter.t[1]);
	}
	return (inter);
}

t_intersection	calculate_ray_plane_intersections(t_ray ray_in, \
					t_plane *plane)
{
	t_intersection	inter;
	t_ray			ray;

	ray = transform_ray(ray_in, plane->inverse);
	inter = (t_intersection){PL, 0, .plane = plane};
	if (are_equals(ray.vector.y, 0))
		return (inter);
	inter.count = 1;
	inter.t[0] = -ray.point.y / ray.vector.y;
	inter.hit_point[0] = calculate_ray_position(ray_in, inter.t[0]);
	return (inter);
}

static int	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;
	double	point;

	x = ray.point.x + t * ray.vector.x;
	z = ray.point.z + t * ray.vector.z;
	point = x * x + z * z;
	if (point <= 1 + EPSILON)
		return (1);
	return (0);
}

static void	calculate_intersect_caps(t_ray ray_in, t_ray ray, \
			t_cylinder *cylinder, t_intersection *inter)
{
	double	t;

	if (are_equals(ray.vector.y, 0))
		return ;
	t = (cylinder->min - ray.point.y) / ray.vector.y;
	if (check_cap(ray, t))
	{
		inter->hit_point[inter->count] = calculate_ray_position(ray_in, t);
		inter->t[inter->count] = t;
		inter->count++;
	}
	t = (cylinder->max - ray.point.y) / ray.vector.y;
	if (check_cap(ray, t))
	{
		inter->hit_point[inter->count] = calculate_ray_position(ray_in, t);
		inter->t[inter->count] = t;
		inter->count++;
	}
}

t_intersection	calculate_ray_cylinder_intersections(t_ray ray_in, \
					t_cylinder *cylinder)
{
	int				i;
	double			y;
	t_intersection	inter;
	t_discriminant	disc;
	t_ray			ray;

	ray = transform_ray(ray_in, cylinder->inverse);
	inter = (t_intersection){CY, 0, .cylinder = cylinder};
	disc = calculate_discriminant_ray_cylinder(ray);
	if (disc.discriminant >= -EPSILON)
	{
		i = -1;
		while (++i < 2)
		{
			y = ray.point.y + disc.t[i] * ray.vector.y;
			if (y > cylinder->min && y < cylinder->max)
			{
				inter.t[inter.count] = disc.t[i];
				inter.hit_point[inter.count++] \
					= calculate_ray_position(ray_in, inter.t[i]);
			}
		}
	}
	calculate_intersect_caps(ray_in, ray, cylinder, &inter);
	return (inter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:40:16 by byoshimo          #+#    #+#             */
/*   Updated: 2023/10/03 18:12:35 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	validate_sphere_texture(t_rt *rt, int sp)
{
	rt->spheres[sp].texture = mlx_load_png(rt->element[3]);
	if (!rt->spheres[sp].texture)
		return (0);
	rt->spheres[sp].color.red = TEXTURE;
	rt->spheres[sp].color1.red = NORMAL;
	return (1);
}

void	validate_sphere(t_rt *rt, int sp)
{
	if (!rt->element[1] || !rt->element[2] || !rt->element[3] || rt->element[4])
		print_error(ARG_SP, rt);
	rt->coordinates = ft_split(rt->element[1], ',');
	if (!validate_coordinates(rt->coordinates))
		print_error(CENTER_SP, rt);
	set_coordinates(&rt->spheres[sp].point, rt->coordinates, POINT);
	free_ptrptr(&rt->coordinates);
	if (!validate_double(rt->element[2]))
		print_error(D_DIAM_SP, rt);
	rt->spheres[sp].diameter = ft_atod(rt->element[2]);
	if (rt->spheres[sp].diameter <= EPSILON)
		print_error(R_DIAM_SP, rt);
	rt->spheres[sp].color1.red = NORMAL;
	rt->color = ft_split(rt->element[3], ':');
	if (!validate_object_color(rt, SP, sp) && !validate_sphere_texture(rt, sp))
		print_error(COLOR_SP, rt);
	free_ptrptr(&rt->color);
}

void	validate_plane(t_rt *rt, int pl)
{
	if (!rt->element[1] || !rt->element[2] || !rt->element[3] || rt->element[4])
		print_error(ARG_PL, rt);
	rt->coordinates = ft_split(rt->element[1], ',');
	if (!validate_coordinates(rt->coordinates))
		print_error(POINT_PL, rt);
	set_coordinates(&rt->planes[pl].point, rt->coordinates, POINT);
	free_ptrptr(&rt->coordinates);
	rt->coordinates = ft_split(rt->element[2], ',');
	if (!validate_coordinates(rt->coordinates))
		print_error(NORMAL_PL, rt);
	set_coordinates(&rt->planes[pl].vector, rt->coordinates, VECTOR);
	if (!validate_normalized_vector(rt->planes[pl].vector))
		print_error(N_NORMAL_PL, rt);
	free_ptrptr(&rt->coordinates);
	rt->planes[pl].color1.red = NORMAL;
	rt->color = ft_split(rt->element[3], ':');
	if (!validate_object_color(rt, PL, pl))
		print_error(COLOR_PL, rt);
	free_ptrptr(&rt->color);
}

static void	validate_cylinder_aux(t_rt *rt, int cy)
{
	if (!validate_double(rt->element[4]))
		print_error(D_HEIGHT_CY, rt);
	rt->cylinders[cy].height = ft_atod(rt->element[4]);
	if (rt->cylinders[cy].height <= EPSILON)
		print_error(R_HEIGHT_CY, rt);
	rt->cylinders[cy].max = rt->cylinders[cy].height / 2;
	rt->cylinders[cy].min = -rt->cylinders[cy].max;
	rt->cylinders[cy].color1.red = NORMAL;
	rt->color = ft_split(rt->element[5], ':');
	if (!validate_object_color(rt, CY, cy))
		print_error(COLOR_CY, rt);
	free_ptrptr(&rt->color);
}

void	validate_cylinder(t_rt *rt, int cy)
{
	if (!rt->element[1] || !rt->element[2] || !rt->element[3] \
		|| !rt->element[4] || !rt->element[5] || rt->element[6])
		print_error(ARG_CY, rt);
	rt->coordinates = ft_split(rt->element[1], ',');
	if (!validate_coordinates(rt->coordinates))
		print_error(CENTER_CY, rt);
	set_coordinates(&rt->cylinders[cy].point, rt->coordinates, POINT);
	free_ptrptr(&rt->coordinates);
	rt->coordinates = ft_split(rt->element[2], ',');
	if (!validate_coordinates(rt->coordinates))
		print_error(VECTOR_CY, rt);
	set_coordinates(&rt->cylinders[cy].vector, rt->coordinates, VECTOR);
	if (!validate_normalized_vector(rt->cylinders[cy].vector))
		print_error(N_VECTOR_CY, rt);
	free_ptrptr(&rt->coordinates);
	if (!validate_double(rt->element[3]))
		print_error(D_DIAM_CY, rt);
	rt->cylinders[cy].diameter = ft_atod(rt->element[3]);
	if (rt->cylinders[cy].diameter <= EPSILON)
		print_error(R_DIAM_CY, rt);
	validate_cylinder_aux(rt, cy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:00:22 by byoshimo          #+#    #+#             */
/*   Updated: 2023/09/27 14:32:58 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	validate_element(t_rt *rt)
{
	if (!ft_strncmp(rt->element[0], "A", 2))
		validate_amb_light(rt);
	else if (!ft_strncmp(rt->element[0], "C", 2))
		validate_camera(rt);
	else if (!ft_strncmp(rt->element[0], "L", 2))
		rt->num_lights++;
	else if (!ft_strncmp(rt->element[0], "sp", 3))
		rt->num_sp++;
	else if (!ft_strncmp(rt->element[0], "pl", 3))
		rt->num_pl++;
	else if (!ft_strncmp(rt->element[0], "cy", 3))
		rt->num_cy++;
	else if (!ft_strncmp(rt->element[0], "co", 3))
		rt->num_co++;
	else
		print_error(INV_ELEMENT, rt);
}

static void	validate_object_cylinder_cone(t_rt *rt)
{
	static int	cy = 0;
	static int	co = 0;

	if (!ft_strncmp(rt->element[0], "cy", 3))
	{
		validate_cylinder(rt, cy);
		cy++;
	}
	else if (!ft_strncmp(rt->element[0], "co", 3))
	{
		validate_cone(rt, co);
		co++;
	}
}

static void	validate_object(t_rt *rt)
{
	static int	lights = 0;
	static int	sp = 0;
	static int	pl = 0;

	if (!ft_strncmp(rt->element[0], "L", 2))
	{
		validate_light(rt, lights);
		lights++;
	}
	else if (!ft_strncmp(rt->element[0], "sp", 3))
	{
		validate_sphere(rt, sp);
		sp++;
	}
	else if (!ft_strncmp(rt->element[0], "pl", 3))
	{
		validate_plane(rt, pl);
		pl++;
	}
	validate_object_cylinder_cone(rt);
}

static void	add_objects(t_rt *rt)
{
	int	i;

	i = 0;
	while (rt->elements[i])
	{
		rt->element = ft_split(rt->elements[i], ' ');
		validate_object(rt);
		free_ptrptr(&rt->element);
		i++;
	}
}

void	parser(t_rt *rt)
{
	int	i;

	i = 0;
	while (rt->elements[i])
	{
		rt->element = ft_split(rt->elements[i], ' ');
		validate_element(rt);
		free_ptrptr(&rt->element);
		i++;
	}
	if (!rt->amb_light.amb_light || !rt->camera.camera || !rt->num_lights)
		print_error(MISS_ELEMENT, rt);
	rt->lights = (t_light *)ft_calloc(rt->num_lights + 1, sizeof(t_light));
	if (rt->num_sp)
		rt->spheres = (t_sphere *)ft_calloc(rt->num_sp + 1, sizeof(t_sphere));
	if (rt->num_pl)
		rt->planes = (t_plane *)ft_calloc(rt->num_pl + 1, sizeof(t_plane));
	if (rt->num_cy)
		rt->cylinders = (t_cylinder *)ft_calloc(rt->num_cy + 1, \
			sizeof(t_cylinder));
	if (rt->num_co)
		rt->cones = (t_cone *)ft_calloc(rt->num_co + 1, sizeof(t_cone));
	add_objects(rt);
	free_ptrptr(&rt->elements);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_object_color_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:48:47 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:10 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	set_object_colors(t_rt *rt, int type_i[2], \
				char **color, char **color1)
{
	if (type_i[0] == SP)
	{
		set_color(&rt->spheres[type_i[1]].color, color);
		if (color1)
			set_color(&rt->spheres[type_i[1]].color1, color1);
	}
	else if (type_i[0] == PL)
	{
		set_color(&rt->planes[type_i[1]].color, color);
		if (color1)
			set_color(&rt->planes[type_i[1]].color1, color1);
	}
	else if (type_i[0] == CY)
	{
		set_color(&rt->cylinders[type_i[1]].color, color);
		if (color1)
			set_color(&rt->cylinders[type_i[1]].color1, color1);
	}
	else
	{
		set_color(&rt->cones[type_i[1]].color, color);
		if (color1)
			set_color(&rt->cones[type_i[1]].color1, color1);
	}
}

static int	validate_cb_color(t_rt *rt, int type_i[2])
{
	char	**color;
	char	**color1;

	if (ft_strncmp(rt->color[0], "cb", 3))
		return (0);
	color = ft_split(rt->color[1], ',');
	color1 = ft_split(rt->color[2], ',');
	if (!validate_color(color) || !validate_color(color1))
	{
		free_ptrptr(&color);
		free_ptrptr(&color1);
		return (0);
	}
	set_object_colors(rt, type_i, color, color1);
	free_ptrptr(&color);
	free_ptrptr(&color1);
	return (1);
}

int	validate_object_color(t_rt *rt, int type, int i)
{
	char	**color;
	int		type_i[2];

	type_i[0] = type;
	type_i[1] = i;
	if (!rt->color[1])
	{
		color = ft_split(rt->color[0], ',');
		if (!validate_color(color))
		{
			free_ptrptr(&color);
			return (0);
		}
		set_object_colors(rt, type_i, color, NULL);
		free_ptrptr(&color);
		return (1);
	}
	else if (!rt->color[2])
		return (0);
	return (validate_cb_color(rt, type_i));
}

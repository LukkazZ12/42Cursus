/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:59:40 by lucade-s          #+#    #+#             */
/*   Updated: 2023/09/09 13:07:18 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	add_colors(t_color a, t_color b)
{
	int	red;
	int	green;
	int	blue;

	red = a.red + b.red;
	if (red > 255)
		red = 255;
	green = a.green + b.green;
	if (green > 255)
		green = 255;
	blue = a.blue + b.blue;
	if (blue > 255)
		blue = 255;
	return ((t_color){red, green, blue});
}

t_color	subtract_colors(t_color a, t_color b)
{
	int	red;
	int	green;
	int	blue;

	red = a.red - b.red;
	if (red < 0)
		red = 0;
	green = a.green - b.green;
	if (green < 0)
		green = 0;
	blue = a.blue - b.blue;
	if (blue < 0)
		blue = 0;
	return ((t_color){red, green, blue});
}

t_color	multiply_color_by_scalar(double scalar, t_color a)
{
	if (scalar > 1)
		scalar = 1;
	if (scalar < 0)
		scalar = 0;
	return ((t_color){scalar * a.red, scalar * a.green, scalar * a.blue});
}

t_color	multiply_colors(t_color a, t_color b)
{
	int	red;
	int	green;
	int	blue;

	red = a.red * b.red / 255;
	green = a.green * b.green / 255;
	blue = a.blue * b.blue / 255;
	return ((t_color){red, green, blue});
}

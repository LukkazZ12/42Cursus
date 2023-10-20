/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_texture_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:18:07 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/03 17:34:26 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static t_coordinates	calculate_map(t_intersections *hit)
{
	double	theta;
	double	phi;
	double	raw_u;

	theta = atan2(hit->o_point.x, hit->o_point.z);
	raw_u = theta / (2 * M_PI);
	if (hit->type == CO)
		return ((t_coordinates){20 * (1 - (raw_u + 0.5)), \
			4 * hit->o_point.y, 0, 0});
	phi = acos(hit->o_point.y);
	if (hit->sphere->color.red == TEXTURE)
		return ((t_coordinates){1 - (raw_u + 0.5), \
			1 - phi / M_PI, 0, 0});
	return ((t_coordinates){16 * (1 - (raw_u + 0.5)), \
		8 * (1 - phi / M_PI), 0, 0});
}

t_color	draw_checkerboard(t_intersections *hit, t_color color, t_color color1)
{
	t_coordinates	point;
	t_coordinates	u_v;

	if (hit->type == SP || hit->type == CO)
	{
		u_v = calculate_map(hit);
		u_v.z = floor(u_v.x);
		u_v.w = floor(u_v.y);
		if (are_equals(fmod(u_v.z + u_v.w, 2), 0))
			return (color);
		else
			return (color1);
	}
	point = create_point(floor(4 * hit->o_point.x), \
		floor(4 * hit->o_point.y), floor(4 * hit->o_point.z));
	if (are_equals(fmod(point.x + point.y + point.z, 2), 0))
		return (color);
	return (color1);
}

t_color	draw_texture(t_intersections *hit)
{
	int				pixel;
	t_coordinates	u_v;
	t_mlx_texture	*texture;

	u_v = calculate_map(hit);
	u_v.z = round(u_v.x * (hit->sphere->texture->width - 1));
	u_v.y = 1 - u_v.y;
	u_v.w = round(u_v.y * (hit->sphere->texture->height - 1));
	texture = hit->sphere->texture;
	pixel = (u_v.w * texture->width + u_v.z) * 4;
	return ((t_color){texture->pixels[pixel], texture->pixels[pixel + 1], \
		texture->pixels[pixel + 2]});
}

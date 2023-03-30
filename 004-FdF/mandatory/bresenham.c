/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mlx_put_pixel_img(t_data *data, t_point map_aux1)
{
	char	*dst;

	if (map_aux1.x > WIN_WIDTH || map_aux1.x < 0
		|| map_aux1.y > WIN_HEIGHT || map_aux1.y < 0)
		return ;
	dst = data->addr_ptr + ((int)map_aux1.y * data->line_length
			+ (int)map_aux1.x * data->bits_per_pixel / 8);
	*(unsigned int *)dst = map_aux1.color;
}

static void	angle_up_45(t_data *data, t_point map_aux1, t_point map_aux2)
{
	data->step = 1;
	data->e = 0;
	if (data->dy < 0)
	{
		data->step = -1;
		data->dy *= -1;
	}
	while ((int)map_aux1.y != (int)map_aux2.y)
	{
		mlx_put_pixel_img(data, map_aux1);
		map_aux1.y += data->step;
		data->e += 2 * data->dx;
		if (data->e >= 2 * data->dy)
		{
			map_aux1.x++;
			data->e -= 2 * data->dy;
		}
	}
}

static void	angle_low_45(t_data *data, t_point map_aux1, t_point map_aux2)
{
	data->step = 1;
	data->e = 0;
	if (data->dy < 0)
	{
		data->step = -1;
		data->dy *= -1;
	}
	while ((int)map_aux1.x <= (int)map_aux2.x)
	{
		map_aux1.x++;
		mlx_put_pixel_img(data, map_aux1);
		data->e += 2 * data->dy;
		if (data->e >= 2 * data->dx)
		{
			map_aux1.y += data->step;
			data->e -= 2 * data->dx;
		}
	}
}

void	bresenham(t_data *data)
{
	t_point	map_aux1;
	t_point	map_aux2;

	if (data->map[data->aux_rows][data->aux_cols].x > data->map[data->aux_rows
		+ data->ver[0]][data->aux_cols + data->ver[1]].x)
	{
		map_aux1 = data->map[data->aux_rows + data->ver[0]]
		[data->aux_cols + data->ver[1]];
		map_aux2 = data->map[data->aux_rows][data->aux_cols];
		map_aux1.color = map_aux2.color;
	}
	else
	{
		map_aux1 = data->map[data->aux_rows][data->aux_cols];
		map_aux2 = data->map[data->aux_rows + data->ver[0]]
		[data->aux_cols + data->ver[1]];
	}
	data->dx = map_aux2.x - map_aux1.x;
	data->dy = map_aux2.y - map_aux1.y;
	if (abs(data->dy) > abs(data->dx))
		angle_up_45(data, map_aux1, map_aux2);
	else
		angle_low_45(data, map_aux1, map_aux2);
}

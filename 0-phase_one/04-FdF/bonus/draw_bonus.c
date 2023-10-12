/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/12 19:02:08 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	matrix(t_data *data)
{
	double	alpha;

	alpha = atan(M_SQRT2 + data->angle);
	data->sin_a = sin(alpha);
	data->cos_a = cos(alpha);
	data->sin_b = sin(M_PI_4);
	data->cos_b = cos(M_PI_4);
}

static void	centralize(t_data *data)
{
	int	center[2];

	data->aux_rows = 0;
	data->aux_cols = 0;
	center[0] = data->map[0][data->cols - 1].x - data->map[data->rows - 1][0].x
		- 2 * (data->map[0][0].x - data->map[data->rows - 1][0].x);
	center[1] = data->map[data->rows - 1][data->cols - 1].y - data->map[0][0].y;
	while (data->aux_rows < data->rows)
	{
		while (data->aux_cols < data->cols)
		{
			data->map[data->aux_rows][data->aux_cols].x += (WIN_WIDTH
					- center[0]) / 2 - data->vert;
			data->map[data->aux_rows][data->aux_cols].y += (WIN_HEIGHT
					- center[1]) / 2 - data->hor;
			data->aux_cols++;
		}
		data->aux_cols = 0;
		data->aux_rows++;
	}
}

static void	transformation(t_data *data)
{
	matrix(data);
	data->aux_rows = 0;
	data->aux_cols = 0;
	while (data->aux_rows < data->rows)
	{
		while (data->aux_cols < data->cols)
		{
			data->x = data->map[data->aux_rows][data->aux_cols].x;
			data->y = data->map[data->aux_rows][data->aux_cols].y;
			data->z = data->map[data->aux_rows][data->aux_cols].z;
			data->map[data->aux_rows][data->aux_cols].x = data->cos_b
				* data->x - data->sin_b * data->y;
			data->map[data->aux_rows][data->aux_cols].y = data->cos_a
				* data->sin_b * data->x + data->cos_a
				* data->cos_b * data->y - data->sin_a * data->z
				* data->z_scale * data->zoom;
			data->aux_cols++;
		}
		data->aux_cols = 0;
		data->aux_rows++;
	}
	centralize(data);
}

void	draw_lines(t_data *data)
{
	transformation(data);
	data->aux_rows = 0;
	data->aux_cols = 0;
	while (data->aux_rows < data->rows)
	{
		while (data->aux_cols < data->cols)
		{
			if (data->aux_cols < data->cols - 1)
			{
				data->ver[0] = 0;
				data->ver[1] = 1;
				bresenham(data);
			}
			if (data->aux_rows < data->rows - 1)
			{
				data->ver[0] = 1;
				data->ver[1] = 0;
				bresenham(data);
			}
			data->aux_cols++;
		}
		data->aux_cols = 0;
		data->aux_rows++;
	}
}

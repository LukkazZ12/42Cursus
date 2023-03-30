/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	copy(t_data *data, t_data my_data)
{
	data->aux_rows = 0;
	data->aux_cols = 0;
	while (data->aux_rows < data->rows)
	{
		while (data->aux_cols < data->cols)
		{
			data->map[data->aux_rows][data->aux_cols].x
				= my_data.map[data->aux_rows][data->aux_cols].x;
			data->map[data->aux_rows][data->aux_cols].y
				= my_data.map[data->aux_rows][data->aux_cols].y;
			data->map[data->aux_rows][data->aux_cols].z
				= my_data.map[data->aux_rows][data->aux_cols].z;
			data->map[data->aux_rows][data->aux_cols].color
				= my_data.map[data->aux_rows][data->aux_cols].color;
			data->aux_cols++;
		}
		data->aux_cols = 0;
		data->aux_rows++;
	}
}

static void	draw(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->addr_ptr = mlx_get_data_addr(data->img_ptr,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	draw_lines(data);
}

int	mlx_render_frame(t_data *my_data)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		data->er = 5;
		error(data);
	}
	*data = (t_data){0};
	data->mlx_ptr = my_data->mlx_ptr;
	data->win_ptr = my_data->win_ptr;
	data->rows = my_data->rows;
	data->cols = my_data->cols;
	data->z_scale = my_data->z_scale;
	data->hor = my_data->hor;
	data->vert = my_data->vert;
	malloc_map(data);
	copy(data, *my_data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	free_map(data, data->rows);
	free(data);
	return (0);
}

int	fdf_keys(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		mlx_close_win(data);
	if (keycode == KEY_W_UP && data->z_scale < MAX_Z)
		data->z_scale += 0.25;
	else if (keycode == KEY_S_DOWN && data->z_scale > -MAX_Z)
		data->z_scale -= 0.25;
	else if (keycode == KEY_UP && data->hor > -MAX_HOR)
		data->hor -= 5;
	else if (keycode == KEY_DOWN && data->hor < MAX_HOR)
		data->hor += 5;
	else if (keycode == KEY_RIGHT && data->vert < MAX_VERT)
		data->vert += 5;
	else if (keycode == KEY_LEFT && data->vert > -MAX_VERT)
		data->vert -= 5;
	mlx_render_frame(data);
	return (0);
}

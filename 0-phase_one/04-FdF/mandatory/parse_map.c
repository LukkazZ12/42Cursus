/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_map(t_data *data)
{
	data->map = malloc(sizeof(t_point) * (data->rows + 1));
	if (data->map == NULL)
	{
		data->er = 5;
		error(data);
	}
	data->map[data->rows] = NULL;
	data->aux_rows = data->rows - 1;
	while (data->aux_rows >= 0)
	{
		data->map[data->aux_rows] = malloc(sizeof(t_point) * (data->cols + 1));
		if (data->map[data->aux_rows] == NULL)
		{
			data->er = 6;
			error(data);
		}
		data->map[data->aux_rows][data->cols] = (t_point){0};
		data->aux_rows--;
	}
}

static void	read_z(t_data *data, char **split)
{
	if (ft_strchr(split[data->aux_cols], ','))
	{
		data->z_color = ft_split(split[data->aux_cols], ',');
		if (data->aux_cols == data->cols - 1)
			data->z_color[1][ft_strlen(data->z_color[1]) - 1] = '\0';
		data->map[data->aux_rows][data->aux_cols].z = ft_atoi(data->z_color[0]);
		data->map[data->aux_rows][data->aux_cols].color
			= ft_atohexa(data->z_color[1]);
		free_malloc(data->z_color, 2);
	}
	else
	{
		data->map[data->aux_rows][data->aux_cols].z
			= ft_atoi(split[data->aux_cols]);
		data->map[data->aux_rows][data->aux_cols].color = 0xFFFFFF;
	}
}

static void	apply_scale(t_data *data)
{
	data->scale = WIN_HEIGHT / hypot(data->rows, data->cols);
	data->map[data->aux_rows][data->aux_cols].y
		= data->aux_rows * data->scale;
	data->map[data->aux_rows][data->aux_cols].x
		= data->aux_cols * data->scale;
}

void	parse_map(t_data *data)
{
	char	**split;

	data->aux_rows = 0;
	data->aux_cols = 0;
	data->fd = open(data->map_name, O_RDONLY);
	while (data->aux_rows < data->rows)
	{
		data->res = get_next_line(data->fd);
		split = ft_split(data->res, ' ');
		while (data->aux_cols < data->cols)
		{
			apply_scale(data);
			read_z(data, split);
			data->aux_cols++;
		}
		free_malloc(split, data->cols);
		free(data->res);
		data->aux_cols = 0;
		data->aux_rows++;
	}
	close(data->fd);
}

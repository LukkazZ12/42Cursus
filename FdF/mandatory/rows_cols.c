/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_cols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	cols(t_data *data)
{
	data->cols = 0;
	data->aux_cols = 0;
	while (data->res[data->aux_cols] != '\n'
		&& data->res[data->aux_cols] != '\0')
	{
		while (data->res[data->aux_cols] == ' ')
			data->aux_cols++;
		if (data->res[data->aux_cols] != '\n'
			&& data->res[data->aux_cols] != '\0')
			data->cols++;
		while (data->res[data->aux_cols] != ' '
			&& data->res[data->aux_cols] != '\n'
			&& data->res[data->aux_cols] != '\0')
			data->aux_cols++;
	}
}

static void	invalid_map(t_data *data)
{
	free(data->res);
	{
		data->er = 4;
		error(data);
	}
}

static void	ver_fd(t_data *data)
{
	if (data->fd < 0)
	{
		data->er = 3;
		error(data);
	}
}

void	rows_cols(t_data *data)
{
	int		ver;

	ver = 0;
	data->fd = open(data->map_name, O_RDONLY);
	ver_fd(data);
	data->res = get_next_line(data->fd);
	if (!data->res)
		invalid_map(data);
	cols(data);
	ver = data->cols;
	if (ver == 0)
		invalid_map(data);
	while (data->res && ver == data->cols)
	{
		free(data->res);
		data->res = get_next_line(data->fd);
		data->rows++;
		if (data->res)
			cols(data);
		if (ver != data->cols)
			invalid_map(data);
	}
	free(data->res);
	close(data->fd);
}

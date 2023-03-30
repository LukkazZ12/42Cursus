/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_data *data)
{
	data->rows = 0;
	data->cols = 0;
	rows_cols(data);
	malloc_map(data);
	parse_map(data);
	data->er = 0;
}

int	main(int argc, char	*argv[])
{
	t_data	data;

	if (argc != 2)
	{
		data.er = 1;
		error(&data);
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "FdF_lucade-s");
	if (data.win_ptr == NULL)
	{
		data.er = 2;
		error(&data);
	}
	data.map_name = argv[1];
	init_map(&data);
	mlx_loop_hook(data.mlx_ptr, mlx_render_frame, &data);
	mlx_hook(data.win_ptr, 2, 3, fdf_keys, &data);
	mlx_hook(data.win_ptr, 17, 0, mlx_close_win, &data);
	mlx_loop(data.mlx_ptr);
	free_map(&data, data.rows);
	return (0);
}

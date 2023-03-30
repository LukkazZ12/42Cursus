/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_data *data, int aux_free)
{
	data->aux_rows = aux_free;
	while (data->aux_rows >= 0)
	{
		free(data->map[data->aux_rows]);
		data->aux_rows--;
	}
	free(data->map);
}

int	mlx_close_win(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (data->er == 0)
		free_map(data, data->rows);
	exit(0);
}

void	error(t_data *data)
{
	if (data->er == 1)
		ft_putstr_fd("Error: Invalid parameters.\n", 1);
	else if (data->er == 2)
		ft_putstr_fd("Error: Impossible to create window.\n", 1);
	else if (data->er == 3)
		ft_putstr_fd("Error: Impossible to open the file.\n", 1);
	else if (data->er == 4)
	{
		while (data->res)
		{
			data->res = get_next_line(data->fd);
			free(data->res);
		}
		ft_putstr_fd("Error: Invalid map.\n", 1);
	}
	else if (data->er == 5)
		ft_putstr_fd("Error: Memory Allocation failed.\n", 1);
	else if (data->er == 6)
	{
		ft_putstr_fd("Error: Memory Allocation failed.\n", 1);
		free_map(data, data->aux_rows - 1);
	}
	if (data->er == 3 || data->er == 4 || data->er == 5 || data->er == 6)
		mlx_close_win(data);
	exit(0);
}

void	free_malloc(char **str_free, int i)
{
	while (i >= 0)
	{
		free(str_free[i]);
		i--;
	}
	free(str_free);
}

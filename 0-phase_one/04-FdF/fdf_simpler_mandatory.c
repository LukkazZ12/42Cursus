/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/01 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// VERIFICAR FD < 0 E FAZER MENSAGEM
	// TIRAR LIBRARY PRINTF
	// ESCALA Z
	// VERIFICAR SE O MAPA SÓ TEM DÍGITOS
	// VERIFICAR QUANDO O ARQUIVO NÃO EXISTE
	// FREE MAP

#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"

#define WIN_HEIGHT 900
#define WIN_WIDTH 1800
#define KEY_ESCAPE 65307
#define KEY_UP 65362
#define KEY_DOWN 65364

typedef struct s_point {
	double	x;
	double	y;
	double	z;
	double	color;
}			t_point;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	char	*map_name;
	t_point	**map;
	int		fd;
	int		rows;
	int		cols;
	int		aux_rows;
	int		aux_cols;
	int		ver[2];
	int		dx;
	int		dy;
	int		e;
	int		step;
}			t_data;

typedef struct s_proj {
	double	scale;
	double	sin_a;
	double	cos_a;
	double	sin_b;
	double	cos_b;
	double	x;
	double	y;
	double	z;
	char	**z_color;
	double	z_value;
}			t_proj;

int	mlx_close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->aux_rows = data->rows;
	while (data->aux_rows >= 0)
	{
		free(data->map[data->aux_rows]);
		data->aux_rows-error-;
	}
	free(data->map);
	free(data->mlx_ptr);
	exit(0);
}

int	mlx_handle_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		mlx_close_win(data);
	return (1);
}

void	mlx_put_pixel_img(t_data *data, t_point map_aux1)
{
	char	*dst;

	if (map_aux1.x > WIN_WIDTH || map_aux1.x < 0
		|| map_aux1.y > WIN_HEIGHT || map_aux1.y < 0)
		return ;
	dst = data->addr_ptr + ((int)map_aux1.y * data->line_length
			+ (int)map_aux1.x * data->bits_per_pixel / 8);
	*(unsigned int *)dst = map_aux1.color;
}

void	cols(t_data *data, char *res)
{
	data->cols = 0;
	data->aux_cols = 0;
	while (res[data->aux_cols] != '\n' && res[data->aux_cols] != '\0')
	{
		while (res[data->aux_cols] == ' ')
			data->aux_cols++;
		if (res[data->aux_cols] != '\n' && res[data->aux_cols] != '\0')
			data->cols++;
		while (res[data->aux_cols] != ' ' && res[data->aux_cols] != '\n'
			&& res[data->aux_cols] != '\0')
			data->aux_cols++;
	}
}

int	rows_cols(t_data *data)
{
	int		ver;
	char	*res;

	ver = 0;
	data->fd = open(data->map_name, O_RDONLY);
	if (data->fd < 0)
		return (1);
	res = get_next_line(data->fd);
	cols(data, res);
	ver = data->cols;
	while (res && ver == data->cols && ver != 0)
	{
		free(res);
		res = get_next_line(data->fd);
		data->rows++;
		if (res)
			cols(data, res);
		if (ver != data->cols)
			data->cols = 0;
	}
	free(res);
	close(data->fd);
	return (0);
}

void	malloc_map(t_data *data)
{
	data->map = malloc(sizeof(t_point) * (data->rows + 1));
	data->map[data->rows] = NULL;
	data->aux_rows = data->rows - 1;
	while (data->aux_rows >= 0)
	{
		data->map[data->aux_rows] = malloc(sizeof(t_point) * (data->cols + 1));
		data->map[data->aux_rows][data->cols] = (t_point){0};
		data->aux_rows--;
	}
}

void	matrix(t_proj *proj, t_data *data)
{
	double	alpha;

	alpha = atan(M_SQRT2);
	proj->sin_a = sin(alpha);
	proj->cos_a = cos(alpha);
	proj->sin_b = sin(M_PI_4);
	proj->cos_b = cos(M_PI_4);
	proj->scale = WIN_HEIGHT / hypot(data->rows, data->cols);
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

void	read_z(t_data *data, t_proj *proj, char **split)
{
	if (ft_strchr(split[data->aux_cols], ','))
	{
		proj->z_color = ft_split(split[data->aux_cols], ',');
		if (data->aux_cols == data->cols - 1)
			proj->z_color[1][ft_strlen(proj->z_color[1]) - 1] = '\0';
		data->map[data->aux_rows][data->aux_cols].z = ft_atoi(proj->z_color[0]);
		data->map[data->aux_rows][data->aux_cols].color
			= ft_atohexa(proj->z_color[1]);
		free_malloc(proj->z_color, 2);
	}
	else
	{
		data->map[data->aux_rows][data->aux_cols].z
			= ft_atoi(split[data->aux_cols]);
		data->map[data->aux_rows][data->aux_cols].color = 0xFFFFFF;
	}
}

void	centralize(t_data *data)
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
					- center[0]) / 2;
			data->map[data->aux_rows][data->aux_cols].y += (WIN_HEIGHT
					- center[1]) / 2;
			data->aux_cols++;
		}
		data->aux_cols = 0;
		data->aux_rows++;
	}
}

void	transformation(t_data *data, t_proj *proj)
{
	data->aux_rows = 0;
	data->aux_cols = 0;
	while (data->aux_rows < data->rows)
	{
		while (data->aux_cols < data->cols)
		{
			proj->x = data->map[data->aux_rows][data->aux_cols].x;
			proj->y = data->map[data->aux_rows][data->aux_cols].y;
			proj->z = data->map[data->aux_rows][data->aux_cols].z;
			data->map[data->aux_rows][data->aux_cols].x = proj->cos_b
				* proj->x - proj->sin_b * proj->y;
			data->map[data->aux_rows][data->aux_cols].y = proj->cos_a
				* proj->sin_b * proj->x + proj->cos_a
				* proj->cos_b * proj->y - proj->sin_a * proj->z;
			data->aux_cols++;
		}
		data->aux_cols = 0;
		data->aux_rows++;
	}
	centralize(data);
}

void	apply_scale(t_data *data, t_proj *proj)
{
	data->map[data->aux_rows][data->aux_cols].y
				= data->aux_rows * proj->scale;
			data->map[data->aux_rows][data->aux_cols].x
				= data->aux_cols * proj->scale;
}

void	parse_map(t_data *data, t_proj *proj)
{
	char	*res;
	char	**split;

	data->aux_rows = 0;
	data->aux_cols = 0;
	data->fd = open(data->map_name, O_RDONLY);
	while (data->aux_rows < data->rows)
	{
		res = get_next_line(data->fd);
		split = ft_split(res, ' ');
		while (data->aux_cols < data->cols)
		{
			apply_scale(data, proj);
			read_z(data, proj, split);
			data->aux_cols++;
		}
		free_malloc(split, data->cols);
		free(res);
		data->aux_cols = 0;
		data->aux_rows++;
	}
	transformation(data, proj);
	close(data->fd);
}

void	angle_up_45(t_data *data, t_point map_aux1, t_point map_aux2)
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

void	angle_low_45(t_data *data, t_point map_aux1, t_point map_aux2)
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

void	draw_lines(t_data *data)
{
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

int	mlx_render_frame(t_data *my_data)
{
	t_data	*data;
	
	data = my_data;
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->addr_ptr = mlx_get_data_addr(data->img_ptr,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	return (0);
}

int	main(int argc, char	*argv[])
{
	t_data	data;
	t_proj	proj;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid parameters.\n", 1);
		return (1);
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "FdF_lucade-s");
	data.map_name = argv[1];
	data.rows = 0;
	data.cols = 0;
	rows_cols(&data);
	malloc_map(&data);
	matrix(&proj, &data);
	parse_map(&data, &proj);
	proj.z_value = 1;
	mlx_key_hook(data.win_ptr, mlx_handle_key_press, &data);
	mlx_loop_hook(data.mlx_ptr, mlx_render_frame, &data);
	mlx_hook(data.win_ptr, 17, 0, mlx_close_win, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

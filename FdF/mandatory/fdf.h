/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:36 by lucade-s          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:36 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

# define WIN_HEIGHT 900
# define WIN_WIDTH 1800
# define KEY_ESCAPE 65307

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
	char	*res;
	int		rows;
	int		cols;
	int		aux_rows;
	int		aux_cols;
	int		ver[2];
	int		dx;
	int		dy;
	int		e;
	int		step;
	double	scale;
	double	sin_a;
	double	cos_a;
	double	sin_b;
	double	cos_b;
	double	x;
	double	y;
	double	z;
	char	**z_color;
	int		er;
}			t_data;

void	rows_cols(t_data *data);
void	parse_map(t_data *data);
void	malloc_map(t_data *data);
int		fdf_keys(int keycode, t_data *data);
int		mlx_render_frame(t_data *my_data);
void	draw_lines(t_data *data);
void	bresenham(t_data *data);
void	error(t_data *data);
int		mlx_close_win(t_data *data);
void	free_map(t_data *data, int aux_free);
void	free_malloc(char **str_free, int i);

#endif
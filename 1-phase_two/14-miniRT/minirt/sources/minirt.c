/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:57:17 by byoshimo          #+#    #+#             */
/*   Updated: 2023/10/03 18:37:19 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_arg(int argc, char *argv[])
{
	if (argc != 2)
		print_error(USAGE, NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 4))
		print_error(FORMAT, NULL);
}

static void	read_rt(t_rt *rt, char *file)
{
	int		fd;
	int		rd;
	char	c;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(INV_FILE, rt);
	rd = read(fd, &c, 1);
	if (rd == -1)
		print_error(INV_READ, rt);
	while (read(fd, &c, 1))
		rd++;
	close(fd);
	buffer = (char *)ft_calloc(rd + 1, sizeof(char));
	fd = open(file, O_RDONLY);
	read(fd, buffer, rd);
	close(fd);
	rt->elements = ft_split(buffer, '\n');
	free(buffer);
}

static t_rt	*init_rt(void)
{
	t_rt	*rt;

	rt = (t_rt *)ft_calloc(1, sizeof(t_rt));
	rt->material.ambient = 0.1;
	rt->material.diffuse = 0.9;
	rt->material.specular = 0.9;
	rt->material.shininess = 200.0;
	return (rt);
}

static void	close_window(void *parameter)
{
	t_rt	*rt;

	rt = (t_rt *)parameter;
	if (mlx_is_key_down(rt->render.mlx, MLX_KEY_ESCAPE))
		free_rt(rt);
}

int	main(int argc, char *argv[])
{
	t_rt	*rt;

	rt = init_rt();
	check_arg(argc, argv);
	read_rt(rt, argv[1]);
	parser(rt);
	init_object_matrices(rt);
	render(rt);
	mlx_loop_hook(rt->render.mlx, &close_window, rt);
	mlx_loop(rt->render.mlx);
	free_rt(rt);
	return (0);
}

#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	set_output(int *fd)
{
	char	path[300] = {0};
	char	*name = "parser_error";

	sprintf(path, __PATH_TEST_, name);
	*fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	dup2(*fd, 1);
}

void	unset_output(int *fd, int *bkp)
{
	dup2(*bkp, 1);
	close(*fd);
}

char	*read_input(char *name)
{
	int		fd;
	int		rd;
	char	c;
	char	*buffer;

	fd = open(name, O_RDONLY);
	rd = read(fd, &c, 1);
	while (read(fd, &c, 1))
		rd++;
	close(fd);
	buffer = (char *)ft_calloc(rd + 1, sizeof(char));
	fd = open(name, O_RDONLY);
	read(fd, buffer, rd);
	close(fd);
	return (buffer);
}

char	*read_output()
{
	int		fd;
	int		rd;
	char	c;
	char	*buffer;
	char	*name = "fd_test/parser_error.test";

	fd = open(name, O_RDONLY);
	rd = read(fd, &c, 1);
	while (read(fd, &c, 1))
		rd++;
	close(fd);
	buffer = (char *)ft_calloc(rd + 1, sizeof(char));
	fd = open(name, O_RDONLY);
	read(fd, buffer, rd);
	close(fd);
	return (buffer);
}

Test(parser, test_parser_test0) {
	char	*read_in = read_input("unit_test/parser/test_files/test0.txt");
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->elements = ft_split(read_in, '\n');

	parser(rt);

	cr_assert(epsilon_eq(flt, 0.2, rt->amb_light.ratio, EPSILON));
	cr_assert(epsilon_eq(flt, 251, rt->amb_light.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 252, rt->amb_light.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 253, rt->amb_light.color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, -50, rt->camera.point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->camera.point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->camera.vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 70, rt->camera.fov, EPSILON));
	cr_assert(epsilon_eq(flt, -40, rt->light.point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 50, rt->light.point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->light.point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 10, rt->light.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->light.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 255, rt->light.color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, 0.6, rt->light.brightness, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->spheres[0].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0.5, rt->spheres[0].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->spheres[0].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 15, rt->spheres[0].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 25, rt->spheres[0].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 255, rt->spheres[0].color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, 12.5, rt->spheres[0].diameter, EPSILON));
	cr_assert(epsilon_eq(flt, 9, rt->spheres[1].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 8, rt->spheres[1].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 7, rt->spheres[1].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 10, rt->spheres[1].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 255, rt->spheres[1].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 245, rt->spheres[1].color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, 23.9, rt->spheres[1].diameter, EPSILON));
	free_ptrptr(&rt->elements);
	free(rt->spheres);
	free(rt);
	free(read_in);
}

Test(parser, test_parser_test1) {
	char	*read_in = read_input("unit_test/parser/test_files/test1.txt");
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->elements = ft_split(read_in, '\n');

	parser(rt);

	cr_assert(epsilon_eq(flt, 0.8, rt->amb_light.ratio, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->amb_light.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->amb_light.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 2, rt->amb_light.color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, -26, rt->camera.point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0.99, rt->camera.point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 35, rt->camera.point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->camera.vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 65, rt->camera.fov, EPSILON));
	cr_assert(epsilon_eq(flt, -126, rt->light.point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 50.956, rt->light.point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0.1111, rt->light.point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 102, rt->light.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 10, rt->light.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 255, rt->light.color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, 0.1, rt->light.brightness, EPSILON));
	cr_assert(epsilon_eq(flt, -23.6, rt->spheres[0].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0.55555, rt->spheres[0].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20.33, rt->spheres[0].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 151, rt->spheres[0].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 215, rt->spheres[0].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 255, rt->spheres[0].color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, 19.5, rt->spheres[0].diameter, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[0].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->planes[0].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, -15, rt->planes[0].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[0].vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->planes[0].vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[0].vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 25, rt->planes[0].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 36, rt->planes[0].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 85, rt->planes[0].color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, -0.9, rt->planes[1].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 158, rt->planes[1].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 15.23, rt->planes[1].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->planes[1].vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[1].vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[1].vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 255, rt->planes[1].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 136, rt->planes[1].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 18, rt->planes[1].color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, -63.9998, rt->cylinders[0].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 125, rt->cylinders[0].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->cylinders[0].vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 15.9689, rt->cylinders[0].diameter, EPSILON));
	cr_assert(epsilon_eq(flt, 23.98755, rt->cylinders[0].height, EPSILON));
	cr_assert(epsilon_eq(flt, 10, rt->cylinders[0].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 255, rt->cylinders[0].color.blue, EPSILON));
	free_ptrptr(&rt->elements);
	free(rt->spheres);
	free(rt->planes);
	free(rt->cylinders);
	free(rt);
	free(read_in);
}

Test(parser, test_parser_test2) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid element.\n";
	char	*read_str;
	char	*read_in = read_input("unit_test/parser/test_files/test2.txt");
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->elements = ft_split(read_in, '\n');

	pid = fork();
	set_output(&fd);
	if (!pid)
		parser(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->elements);
	free(rt->spheres);
	free(rt);
	free(read_in);
	free(read_str);
}

Test(parser, test_parser_test3) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nSome element (ambient light, camera, light) is missing.\n";
	char	*read_str;
	char	*read_in = read_input("unit_test/parser/test_files/test3.txt");
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->elements = ft_split(read_in, '\n');

	pid = fork();
	set_output(&fd);
	if (!pid)
		parser(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->elements);
	free(rt);
	free(read_in);
	free(read_str);
}

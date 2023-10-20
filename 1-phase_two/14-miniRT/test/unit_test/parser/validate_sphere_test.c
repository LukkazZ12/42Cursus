#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	set_output(int *fd)
{
	char	path[300] = {0};
	char	*name = "validate_sphere_error";

	sprintf(path, __PATH_TEST_, name);
	*fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	dup2(*fd, 1);
}

void	unset_output(int *fd, int *bkp)
{
	dup2(*bkp, 1);
	close(*fd);
}

char	*read_output()
{
	int		fd;
	int		rd;
	char	c;
	char	*buffer;
	char	*name = "fd_test/validate_sphere_error.test";

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

Test(parser, test_validate_sphere_minus_10_0_point_5_20__15_point_8__20_0_254) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("sp -10,0.5,20 15.8 20,0,254", ' ');
	rt->spheres = ft_calloc(2, sizeof(t_sphere));

	validate_sphere(rt, 0);

	cr_assert(epsilon_eq(flt, -10, rt->spheres[0].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0.5, rt->spheres[0].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->spheres[0].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->spheres[0].point.w, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->spheres[0].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->spheres[0].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 254, rt->spheres[0].color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, 15.8, rt->spheres[0].diameter, EPSILON));
	free_ptrptr(&rt->element);
	free(rt->spheres);
	free(rt);
}

Test(parser, test_validate_sphere_minus_10_0_point_5_20__15_point_8__20_0_254__lucas) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid number of arguments on sphere.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->spheres = ft_calloc(2, sizeof(t_sphere));
	rt->element = ft_split("sp -10,0.5,20 15.8 20,0,254 lucas", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_sphere(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->spheres);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_sphere_minus_1r0_0_point_5_20__15_point_8__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid sphere center coordinates.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->spheres = ft_calloc(2, sizeof(t_sphere));
	rt->element = ft_split("sp -1r0,0.5,20 15.8 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_sphere(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->spheres);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_sphere_minus_10_0_point_5_20__1o5_point_8__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid sphere diameter. Diameter is not a double.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->spheres = ft_calloc(2, sizeof(t_sphere));
	rt->element = ft_split("sp -10,0.5,20 1o5.8 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_sphere(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->spheres);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_sphere_minus_10_0_point_5_20__minus_15_point_8__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid sphere diameter. Diameter isn't greater than 0.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->spheres = ft_calloc(2, sizeof(t_sphere));
	rt->element = ft_split("sp -10,0.5,20 -15.8 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_sphere(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->spheres);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_sphere_minus_10_0_point_5_20__15_point_8__20_0_256) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid sphere color.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->spheres = ft_calloc(2, sizeof(t_sphere));
	rt->element = ft_split("sp -10,0.5,20 15.8 20,0,256", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_sphere(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->spheres);
	free(rt);
	free(read_str);
}
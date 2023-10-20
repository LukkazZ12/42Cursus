#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	set_output(int *fd)
{
	char	path[300] = {0};
	char	*name = "validate_cylinder_error";

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
	char	*name = "fd_test/validate_cylinder_error.test";

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

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1_0_0__14_point_2__25__20_0_254) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("cy -10,0.5,20 1,0,0 14.2 25 20,0,254", ' ');
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));

	validate_cylinder(rt, 0);

	cr_assert(epsilon_eq(flt, -10, rt->cylinders[0].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0.5, rt->cylinders[0].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->cylinders[0].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->cylinders[0].point.w, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->cylinders[0].vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].vector.w, EPSILON));
	cr_assert(epsilon_eq(flt, 14.2, rt->cylinders[0].diameter, EPSILON));
	cr_assert(epsilon_eq(flt, 25, rt->cylinders[0].height, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->cylinders[0].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->cylinders[0].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 254, rt->cylinders[0].color.blue, EPSILON));
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1_0_0__14_point_2__25__20_0_254__lucas) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid number of arguments on cylinder.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 1,0,0 14.2 25 20,0,254 lucas", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_1x0_0_point_5_20__1_0_0__14_point_2__25__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder center coordinates.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -1x0,0.5,20 1,0,0 14.2 25 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1i_0_0__14_point_2__25__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder vector.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 1i,0,0 14.2 25 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__2_0_0__14_point_2__25__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder vector. Vector is not normalized.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 2,0,0 14.2 25 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1_0_0__14p_point_2__25__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder diameter. Diameter is not a double.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 1,0,0 14p.2 25 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1_0_0__minus_14_point_2__25__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder diameter. Diameter isn't greater than 0.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 1,0,0 -14.2 25 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1_0_0__14_point_2__2u5__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder height. Height is not a double.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 1,0,0 14.2 2u5 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1_0_0__14_point_2__minus_25__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder height. Height isn't greater than 0.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 1,0,0 14.2 -25 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_cylinders_minus_10_0_point_5_20__1_0_0__14_point_2__25__20_1200_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid cylinder color.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->cylinders = ft_calloc(2, sizeof(t_cylinder));
	rt->element = ft_split("cy -10,0.5,20 1,0,0 14.2 25 20,1200,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_cylinder(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->cylinders);
	free(rt);
	free(read_str);
}

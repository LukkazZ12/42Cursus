#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	set_output(int *fd)
{
	char	path[300] = {0};
	char	*name = "validate_camera_error";

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
	char	*name = "fd_test/validate_camera_error.test";

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

Test(parser, test_validate_camera_50_0_20__0_0_1__70) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C 50,0,20 0,0,1 70", ' ');

	validate_camera(rt);

	cr_assert(epsilon_eq(flt, 50, rt->camera.point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->camera.point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->camera.point.w, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->camera.vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.w, EPSILON));
	cr_assert(epsilon_eq(flt, 70, rt->camera.fov, EPSILON));
	free_ptrptr(&rt->element);
	free(rt);
}

Test(parser, test_validate_camera_minus_75_minus_10_20__0_267261_minus_0_534522_0_801784__70) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C -75,-10,20 0.267261,-0.534522,0.801784 179", ' ');
	
	validate_camera(rt);

	cr_assert(epsilon_eq(flt, -75, rt->camera.point.x, EPSILON));
	cr_assert(epsilon_eq(flt, -10, rt->camera.point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->camera.point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->camera.point.w, EPSILON));
	cr_assert(epsilon_eq(flt, 0.267261, rt->camera.vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, -0.534522, rt->camera.vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0.801784, rt->camera.vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->camera.vector.w, EPSILON));
	cr_assert(epsilon_eq(flt, 179, rt->camera.fov, EPSILON));
	free_ptrptr(&rt->element);
	free(rt);
}

Test(parser, test_validate_camera_50_0_20__0_0_1__70__185) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid number of arguments on camera.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C 50,0,20 0,0,1 70 185", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_camera(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_camera_50_0f_20__0_0_1__70) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid camera point.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C 50,0f,20 0,0,1 70", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_camera(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_camera_50_0_20__0_0_1l__70) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid camera vector.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C 50,0,20 0,0,1l 70", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_camera(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_camera_50_0_20__0_0_2__70) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid camera vector. Vector is not normalized.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C 50,0,20 0,0,2 70", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_camera(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_camera_50_0_20__0_0_1__70k) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid camera horizontal field of view.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C 50,0,20 0,0,1 70k", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_camera(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_camera_50_0_20__0_0_1__250) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid camera horizontal field of view.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("C 50,0,20 0,0,1 250", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_camera(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

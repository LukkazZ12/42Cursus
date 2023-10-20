#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	set_output(int *fd)
{
	char	path[300] = {0};
	char	*name = "validate_plane_error";

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
	char	*name = "fd_test/validate_plane_error.test";

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

Test(parser, test_validate_plane_minus_10_0_point_5_20__1_0_0__20_0_254) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("pl -10,0.5,20 1,0,0 20,0,254", ' ');
	rt->planes = ft_calloc(2, sizeof(t_plane));

	validate_plane(rt, 0);

	cr_assert(epsilon_eq(flt, -10, rt->planes[0].point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0.5, rt->planes[0].point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->planes[0].point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->planes[0].point.w, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->planes[0].vector.x, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[0].vector.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[0].vector.z, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[0].vector.w, EPSILON));
	cr_assert(epsilon_eq(flt, 20, rt->planes[0].color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->planes[0].color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 254, rt->planes[0].color.blue, EPSILON));
	free_ptrptr(&rt->element);
	free(rt->planes);
	free(rt);
}

Test(parser, test_validate_plane_minus_10_0_point_5_20__1_0_0__20_0_254__lucas) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid number of arguments on plane.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->planes = ft_calloc(2, sizeof(t_plane));
	rt->element = ft_split("pl -10,0.5,20 1,0,0 20,0,254 lucas", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_plane(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->planes);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_plane_minus_1u0_0_point_5_20__1_0_0__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid plane point.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->planes = ft_calloc(2, sizeof(t_plane));
	rt->element = ft_split("pl -1u0,0.5,20 1,0,0 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_plane(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->planes);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_plane_minus_10_0_point_5_20__2_0_0__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid plane normal. Normal is not normalized.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->planes = ft_calloc(2, sizeof(t_plane));
	rt->element = ft_split("pl -10,0.5,20 2,0,0 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_plane(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->planes);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_plane_minus_10_0_point_5_20__1h_0_0__20_0_254) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid plane normal.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->planes = ft_calloc(2, sizeof(t_plane));
	rt->element = ft_split("pl -10,0.5,20 1h,0,0 20,0,254", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_plane(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->planes);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_plane_minus_10_0_point_5_20__1_0_0__20_0_256) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid plane color.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->planes = ft_calloc(2, sizeof(t_plane));
	rt->element = ft_split("pl -10,0.5,20 1,0,0 20,0,256", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
	validate_plane(rt, 0);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt->planes);
	free(rt);
	free(read_str);
}

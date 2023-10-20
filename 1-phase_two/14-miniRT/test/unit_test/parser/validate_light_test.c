#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	set_output(int *fd)
{
	char	path[300] = {0};
	char	*name = "validate_light_error";

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
	char	*name = "fd_test/validate_light_error.test";

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

Test(parser, test_validate_light_minus_40_10_0_point_5__0_point_7__125_1_70) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("L -40,10,0.5 0.7 125,1,70", ' ');

	validate_light(rt);

	cr_assert(epsilon_eq(flt, -40, rt->light.point.x, EPSILON));
	cr_assert(epsilon_eq(flt, 10, rt->light.point.y, EPSILON));
	cr_assert(epsilon_eq(flt, 0.5, rt->light.point.z, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->light.point.w, EPSILON));
	cr_assert(epsilon_eq(flt, 125, rt->light.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->light.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 70, rt->light.color.blue, EPSILON));
	cr_assert(epsilon_eq(flt, 0.7, rt->light.brightness, EPSILON));
	free_ptrptr(&rt->element);
	free(rt);
}

Test(parser, test_validate_light_50_0_20__0_point_8__18_25_185__359) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid number of arguments on light.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("L 50,0,20 0.8 18,25,185 359", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_light_5j0_0_20__0_point_8__18_25_185) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid light point.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("L 5j0,0,20 0.8 18,25,185", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_light_50_0_20__0_point__18_25_185) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid light brightness. Brightness is not a double.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("L 50,0,20 0. 18,25,185", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_light_50_0_20__1_point_8__18_25_185) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid light brightness.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("L 50,0,20 1.8 18,25,185", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_light_50_0_20__0_point_8__18_2f5_185) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid light color.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("L 50,0,20 0.8 18,2f5,185", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_light_50_0_20__0_point_8__18_2655_185) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid light color.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("L 50,0,20 0.8 18,2655,185", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(read_str, error, "value expected [ %s ], result [ %s ].\n", read_str, error);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

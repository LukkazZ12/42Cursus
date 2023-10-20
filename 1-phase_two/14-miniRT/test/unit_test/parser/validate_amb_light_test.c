#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	set_output(int *fd)
{
	char	path[300] = {0};
	char	*name = "validate_amb_light_error";

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
	char	*name = "fd_test/validate_amb_light_error.test";

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

Test(parser, test_validate_amb_light_1__0_0_0) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("A 1 0,0,0", ' ');

	validate_amb_light(rt);

	cr_assert(epsilon_eq(flt, 1, rt->amb_light.ratio, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->amb_light.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->amb_light.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->amb_light.color.blue, EPSILON));
	free_ptrptr(&rt->element);
	free(rt);
}

Test(parser, test_validate_amb_light_1__0_1_0) {
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("A 1 0,1,0", ' ');

	validate_amb_light(rt);

	cr_assert(epsilon_eq(flt, 1, rt->amb_light.ratio, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->amb_light.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, 1, rt->amb_light.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, 0, rt->amb_light.color.blue, EPSILON));
	free_ptrptr(&rt->element);
	free(rt);
}

Test(parser, test_validate_amb_light_1__0_0_0__1) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid number of arguments on ambient light.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("A 1 0,0,0 1", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_amb_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_amb_light_1f__0_0_0) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid ambient light ratio. Ratio is not a double.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("A 1f 0,0,0", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_amb_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_amb_light_1_point_2__0_0_0) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid ambient light ratio. Ratio: 0.0 - 1.0.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("A 1.2 0,0,0", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_amb_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

Test(parser, test_validate_amb_light_1__0_0_256) {
	int		fd;
	int		bkp = dup(1);
	pid_t	pid;
	char	*error = "Error\nInvalid ambient light color.\n";
	char	*read_str;
	t_rt	*rt = ft_calloc(1, sizeof(t_rt));
	rt->element = ft_split("A 1 0,0,256", ' ');

	pid = fork();
	set_output(&fd);
	if (!pid)
		validate_amb_light(rt);
	wait(NULL);
	unset_output(&fd, &bkp);
	read_str = read_output();
	cr_assert_str_eq(error, read_str, "value expected [ %s ], result [ %s ].\n", error, read_str);
	free_ptrptr(&rt->element);
	free(rt);
	free(read_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:06:15 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/19 20:10:24 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int er)
{
	if (er == 0)
		ft_putstr_fd("ERROR: Wrong number of arguments.", 1);
	else if (er == 1)
		ft_putstr_fd("ERROR: One of the arguments is not a number.", 1);
	else if (er == 2)
		ft_putstr_fd("ERROR: There is a duplicate argument.", 1);
	else if (er == 3)
		ft_putstr_fd("ERROR: A number is either too big or too small.", 1);
	else
		ft_putstr_fd("ERROR: Memory allocation failed.", 1);
	exit (1);
}

static void	check_duplicate(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoll(argv[i]) == ft_atoll(argv[j]))
				error(2);
			j++;
		}
		i++;
	}
}

void	check_argv(int argc, char *argv[])
{
	int			i;
	int			j;
	long long	n;

	if (argc < 2)
		error(0);
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0' || argv[i][0] == '\0')
			error(1);
		n = ft_atoll(argv[i]);
		if (n < -2147483648 || n > 2147483647)
			error(3);
		i++;
	}
	check_duplicate(argv);
}

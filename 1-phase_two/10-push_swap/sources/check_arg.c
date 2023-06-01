/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:06:15 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/01 20:25:15 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static void	check_duplicate(char *argv[])
{
	int	i;
	int	j;
	int	num;

	num = 0;
	i = 1;
	while (argv[i])
	{
		num = ft_atoll(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (num == ft_atoll(argv[j]))
				error();
			j++;
		}
		i++;
	}
}

void	check_arg(int argc, char *argv[])
{
	int			i;
	int			j;
	long long	n;

	if (argc < 2)
		exit(1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0' || argv[i][0] == '\0')
			error();
		n = ft_atoll(argv[i]);
		if (n > 2147483647)
			error();
		i++;
	}
	check_duplicate(argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:13:37 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/28 21:36:55 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_iswhitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

unsigned int	ft_atoui(const char *nptr)
{
	unsigned int	num;

	while (ft_iswhitespace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	num = 0;
	while (ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - 48);
		if (num > 2147483647)
			return (0);
		nptr++;
	}
	while (ft_iswhitespace(*nptr))
		nptr++;
	if (*nptr)
		return (0);
	return (num);
}

int	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 4 && argc != 5)
	{
		printf("Invalid number of arguments. Try: ./philo");
		printf(" number_of_queens time_to_sashay_way time_to_slay");
		printf(" [optional]number_of_times_each_queen_must_slay\n");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (!ft_atoui(argv[i]))
		{
			printf("One of the parameters is not a number");
			printf(" or a valid number. Try again.");
			return (0);
		}
		i++;
	}
	return (1);
}

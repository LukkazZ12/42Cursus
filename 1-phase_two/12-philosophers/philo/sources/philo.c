/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:12:39 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/28 21:37:11 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_dragrace	dragrace;

	if (!check_args(argc, argv))
		return (1);
	dragrace.num_of_queens = ft_atoui(argv[1]);
	return (0);
}

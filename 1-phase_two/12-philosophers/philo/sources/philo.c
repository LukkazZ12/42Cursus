/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:12:39 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/29 15:48:56 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	the_library_is_officially_closed(t_dragrace *library)
{
	free(library->queens);
	free(library);
}

static int	say_something_funny_silky_nutmeg_ganache(t_dragrace *library)
{
	free(library->queens);
	free(library);
	return (1);
}

static void	*read_the_queens(void *library)
{
	pthread_mutex_lock(&((t_dragrace *)library)->a_queen_is_reading);
	printf("Michelle Visage is so full of semen... Period!\n");
	pthread_mutex_unlock(&((t_dragrace *)library)->a_queen_is_reading);
	return (NULL);
}

static int	reading_is_fundamental(t_dragrace *library)
{
	int	i;

	library->queens = (pthread_t *)malloc(sizeof(pthread_t)
			* (library->num_of_queens));
	pthread_mutex_init(&library->a_queen_is_reading, NULL);
	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_create(&library->queens[i],
				NULL, &read_the_queens, library))
			return (say_something_funny_silky_nutmeg_ganache(library));
		i++;
	}
	i = 0;
	while (i < library->num_of_queens)
	{
		if (pthread_join(library->queens[i], NULL))
			return (say_something_funny_silky_nutmeg_ganache(library));
		i++;
	}
	pthread_mutex_destroy(&library->a_queen_is_reading);
	return (0);
}

static void	the_library_is_open(t_dragrace *library, char *argv[])
{
	library->num_of_queens = ft_atoui(argv[1]);
	library->time_to_sashay_away = ft_atoui(argv[2]);
	library->time_to_read = ft_atoui(argv[3]);
	library->time_to_be_read = ft_atoui(argv[4]);
	if (argv[5])
		library->times_must_read = ft_atoui(argv[5]);
}

int	main(int argc, char *argv[])
{
	t_dragrace	*library;

	if (!hello_hello_hello(argc, argv))
		return (1);
	library = (t_dragrace *)malloc(sizeof(t_dragrace));
	the_library_is_open(library, argv);
	reading_is_fundamental(library);
	the_library_is_officially_closed(library);
	return (0);
}

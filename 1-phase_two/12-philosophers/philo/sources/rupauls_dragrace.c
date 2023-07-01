/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rupauls_dragrace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:12:39 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/01 16:41:58 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

int	main(int argc, char *argv[])
{
	t_library	*library;
	t_queens	*queens;

	if (!hello_hello_hello(argc, argv))
		return (1);
	library = (t_library *)malloc(sizeof(t_library));
	queens = NULL;
	the_library_is_open(&queens, library, argv);
	if (!reading_is_fundamental(queens, library))
		the_library_is_officially_closed(queens, library);
	return (0);
}

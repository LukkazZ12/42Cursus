/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_library_is_officially_closed.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:25:14 by lucade-s          #+#    #+#             */
/*   Updated: 2023/07/04 16:51:28 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "werkroom.h"

void	the_library_is_officially_closed(t_queens *queens, t_library *library)
{
	free(library->queens);
	free(library->glasses);
	free(queens);
	free(library);
}

int	say_something_funny_silky_nutmeg_ganache(t_queens *queens, \
	t_library *library)
{
	free(library->queens);
	free(library->glasses);
	free(queens);
	free(library);
	return (1);
}

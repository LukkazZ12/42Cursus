/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:08:54 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/20 16:16:43 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	terminate(char *error_msg)
{
	if (error_msg)
	{
		ft_putstr_fd("Server error: ", 1);
		ft_putstr_fd(error_msg, 1);
		ft_putstr_fd(".\n", 1);
	}
	exit(1);
}

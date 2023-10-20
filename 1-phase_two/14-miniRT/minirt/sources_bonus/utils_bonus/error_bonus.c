/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:44:16 by byoshimo          #+#    #+#             */
/*   Updated: 2023/09/29 18:11:02 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	print_error(char *error, t_rt *rt)
{
	printf("Error\n%s\n", error);
	if (rt)
		free_rt(rt);
	exit(1);
}

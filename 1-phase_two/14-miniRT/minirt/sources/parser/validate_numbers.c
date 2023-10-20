/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:17:13 by byoshimo          #+#    #+#             */
/*   Updated: 2023/10/10 14:55:18 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_double(char *number)
{
	int	i;

	i = 0;
	if (!number || !number[i])
		return (0);
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (!number[i] || number[i] == '.')
		return (0);
	while (ft_isdigit(number[i]))
		i++;
	if (!number[i])
		return (1);
	if (number[i] == '.')
		i++;
	if (!number[i])
		return (0);
	while (ft_isdigit(number[i]))
		i++;
	if (!number[i])
		return (1);
	return (0);
}

int	validate_int(char *number)
{
	int	i;

	i = 0;
	if (!number || !number[i] || ft_strlen(number) > 3)
		return (0);
	while (ft_isdigit(number[i]))
		i++;
	if (!number[i])
		return (1);
	return (0);
}

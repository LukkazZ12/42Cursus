/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:19:14 by byoshimo          #+#    #+#             */
/*   Updated: 2023/10/03 17:39:13 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_color(char **color)
{
	int	i;

	i = 0;
	while (color && color[i] && validate_int(color[i]))
	{
		if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
			break ;
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int	validate_coordinates(char **coordinates)
{
	int	i;

	i = 0;
	while (coordinates && coordinates[i] && validate_double(coordinates[i]))
		i++;
	if (i != 3)
		return (0);
	return (1);
}

int	validate_normalized_vector(t_coordinates coordinates)
{
	return (are_equals(calculate_vector_magnitude(coordinates), 1));
}

int	validate_angle(char *angle)
{
	return (angle && validate_int(angle) && ft_atoi(angle) >= -EPSILON \
		&& ft_atoi(angle) <= 180 + EPSILON);
}

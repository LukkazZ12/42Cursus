/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:14:59 by byoshimo          #+#    #+#             */
/*   Updated: 2023/08/30 18:31:21 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_coordinates(t_coordinates *dest, char **src, double w)
{
	(*dest).x = ft_atod(src[0]);
	(*dest).y = ft_atod(src[1]);
	(*dest).z = ft_atod(src[2]);
	(*dest).w = w;
}

void	set_color(t_color *dest, char **src)
{
	(*dest).red = ft_atoi(src[0]);
	(*dest).green = ft_atoi(src[1]);
	(*dest).blue = ft_atoi(src[2]);
}

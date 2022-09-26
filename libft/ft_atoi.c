/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:32:02 by lucade-s          #+#    #+#             */
/*   Updated: 2022/09/22 20:33:29 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	num;

	j = 0;
	while ((nptr[j] >= 9 && nptr[j] <= 13) || nptr[j] == 32)
		j++;
	i = j;
	if (nptr[i] != '-' && nptr[i] != '+' && ft_isdigit(nptr[i]) == 0)
		return (0);
	else if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (ft_isdigit(nptr[i + 1]) == 0)
			return (0);
		i++;
	}
	num = 0;
	while (ft_isdigit(nptr[i]) == 1)
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[j] == '-')
		num = -num;
	return (num);
}

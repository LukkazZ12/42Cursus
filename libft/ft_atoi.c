/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:22:35 by byoshimo          #+#    #+#             */
/*   Updated: 2022/09/12 23:22:55 by byoshimo         ###   ########.fr       */
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
		if (ft_isdigit(nptr[i + 1]) != 1)
			return (0);
		i += 1;
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

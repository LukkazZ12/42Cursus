/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:32:02 by lucade-s          #+#    #+#             */
/*   Updated: 2022/09/22 20:33:29 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atohexa(char *nptr)
{
	int		num;
	int		i;
	int		len;
	int		pow_hexa;

	num = 0;
	i = 2;
	len = ft_strlen(&nptr[i]) - 1;
	pow_hexa = pow(16, len);
	while (nptr[i])
	{
		if (nptr[i] >= 'a' && nptr[i] <= 'f')
			nptr[i] = nptr[i] - 32;
		num += (ft_strchr(HEXA, nptr[i]) - &HEXA[0]) * pow_hexa;
		pow_hexa /= 16;
		i++;
	}
	return (num);
}

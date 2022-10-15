/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:33:33 by lucade-s          #+#    #+#             */
/*   Updated: 2022/10/15 21:51:20 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_str(char *num, int n, int aux, int i)
{
	if (n == 0)
		num[0] = '0';
	else if (n > 0)
		aux = n;
	else
	{
		if (n == -2147483648)
		{
			num[10] = '8';
			aux = -(n / 10);
			i--;
		}
		else
			aux = -n;
		num[0] = '-';
	}
	while (aux != 0)
	{
		num[i - 1] = (aux % 10) + 48;
		aux /= 10;
		i--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int		i;
	int		aux;
	char	*num;

	aux = n;
	if (n == 0)
		i = 1;
	else
	{
		i = 0;
		while (aux != 0)
		{
			aux /= 10;
			i++;
		}
		if (n < 0)
			i++;
	}
	num = malloc(i + 1);
	if (num == NULL)
		return (NULL);
	num[i] = '\0';
	ft_itoa_str(num, n, aux, i);
	return (num);
}

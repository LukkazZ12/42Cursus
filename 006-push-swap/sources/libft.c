/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:06:15 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/01 17:11:25 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			sign;
	long long	num;

	sign = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+')
		sign = 1;
	else if (nptr[i] == '-')
		sign = -1;
	if (sign)
		i++;
	num = 0;
	while (nptr[i])
	{
		num = num * 10 + (nptr[i] - 48);
		if ((sign != -1 && num > 2147483647) || num > 2147483648)
			return (2147483648);
		i++;
	}
	if (sign == -1)
		num = sign * num;
	return (num);
}

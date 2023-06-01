/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:24:00 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/20 16:16:39 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		a;
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
			write(fd, "2147483648", 10);
		n = -n;
	}
	a = n % 10;
	c = a + '0';
	if (n <= 9)
	{
		write(fd, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

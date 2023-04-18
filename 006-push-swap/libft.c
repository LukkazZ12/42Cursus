/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:06:15 by lucade-s          #+#    #+#             */
/*   Updated: 2023/04/18 15:45:19 by lucade-s         ###   ########.fr       */
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
	{
		write(fd, &s[i], 1);
		i++;
	}
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

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			j;
	long long	num;

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

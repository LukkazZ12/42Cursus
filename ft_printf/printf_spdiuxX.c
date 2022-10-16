/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_spdiuxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:02:13 by lucade-s          #+#    #+#             */
/*   Updated: 2022/10/16 03:06:56 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		i = write(1, "(null)", 6);
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putptr(unsigned long n)
{
	int	counter;

	if (!n)
		return (write(1, "(nil)", 5));
	counter = 0;
	if (n < 16)
	{
		counter += write(1, "0x", 2);
		counter += write(1, &HEXA_LOW[n % 16], 1);
		return (counter);
	}
	counter += ft_putptr(n / 16);
	counter += write(1, &HEXA_LOW[n % 16], 1);
	return (counter);
}

int	ft_putnbr(int n)
{
	int		counter;
	char	c;

	counter = 0;
	if (n < 0)
	{
		counter += write(1, "-", 1);
		if (n == -2147483648)
		{
			counter += write(1, "2147483648", 10);
			return (counter);
		}
		n = -n;
	}
	c = n % 10 + '0';
	if (n <= 9)
	{
		counter += write(1, &c, 1);
		return (counter);
	}
	counter += ft_putnbr(n / 10);
	counter += write(1, &c, 1);
	return (counter);
}

int	ft_putunbr(unsigned int n)
{
	int		counter;
	char	c;

	counter = 0;
	c = n % 10 + '0';
	if (n <= 9)
	{
		counter += write(1, &c, 1);
		return (counter);
	}
	counter += ft_putnbr(n / 10);
	counter += write(1, &c, 1);
	return (counter);
}

int	ft_puthexa(unsigned long n, char specifier)
{
	int	counter;

	counter = 0;
	if (n < 16)
	{
		if (specifier == 'x')
			counter += write(1, &HEXA_LOW[n % 16], 1);
		else
			counter += write(1, &HEXA_UP[n % 16], 1);
		return (counter);
	}
	counter += ft_puthexa(n / 16, specifier);
	if (specifier == 'x')
		counter += write(1, &HEXA_LOW[n % 16], 1);
	else
		counter += write(1, &HEXA_UP[n % 16], 1);
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:10:33 by lucade-s          #+#    #+#             */
/*   Updated: 2022/10/18 18:13:10 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

static int	ft_printf_specifier(const char *specifier, va_list args)
{
	int				counter;
	int				integer;
	unsigned int	unsinteger;

	counter = 0;
	if (*specifier == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (*specifier == 's')
		counter = ft_putstr(va_arg(args, char *));
	else if (*specifier == 'p')
		counter = ft_putptr(va_arg(args, unsigned long));
	else if (*specifier == 'd' || *specifier == 'i')
		counter = ft_putnbr(va_arg(args, int));
	else if (*specifier == 'u')
		counter = ft_putunbr(va_arg(args, unsigned int));
	else if (*specifier == 'x' || *specifier == 'X')
		counter = ft_puthexa(va_arg(args, unsigned int), *specifier);
	else if (*specifier == '%')
		counter = ft_putchar('%');
	else if (*specifier == ' ')
	{
		while (*specifier == ' ')
			specifier++;
		if (*specifier == 'd' || *specifier == 'i')
		{
			integer = va_arg(args, int);
			if (integer >= 0)
				counter = write(1, " ", 1) + ft_putnbr(integer);
			else
				counter = ft_putnbr(integer);
		}
		else
			counter = -1;
	}
	else if (*specifier == '+')
	{
		while (*specifier == '+')
			specifier++;
		if (*specifier == 'd' || *specifier == 'i')
		{
			integer = va_arg(args, int);
			if (integer >= 0)
				counter = write(1, "+", 1) + ft_putnbr(integer);
			else
				counter = ft_putnbr(integer);
		}
		else
			counter = -1;
	}
	else if (*specifier == '#')
	{
		while (*specifier == '#')
			specifier++;
		if (*specifier == 'x' || *specifier == 'X')
		{
			unsinteger = va_arg(args, unsigned int);
			if (unsinteger != 0)
			{
				if (*specifier == 'x')
					counter = write(1, "0x", 2);
				else
					counter = write(1, "0X", 2);
			}
			counter += ft_puthexa(unsinteger, *specifier);
		}
		else
			counter = -1;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		aux;
	int		aux2;
	char	*c;

	va_start(args, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			aux = 0;
			while (format[aux] == '%')
				aux++;
			format++;
			c = &((char *)format)[aux - 1];
			aux2 = aux;
			if (aux % 2 == 0 || ft_strchr("cspdiuxX +#", *c))
				aux = ft_printf_specifier(format, args);
			else
				aux = -1;
			if (ft_strchr(" +#", *c) && aux2 % 2 != 0)
			{
				while (ft_strchr(" +#", *c))
					c++;
				format = c;
			}
			if (aux == -1)
			{
				counter += ft_putstr((char *)(format - 1));
				write(1, "\nError: no valid specifier found.\n", 34);
				return (counter);
			}
			counter += aux;
		}
		else
			counter += write(1, format, 1);
		format++;
	}
	return (va_end(args), counter);
}

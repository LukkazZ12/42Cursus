/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:10:33 by lucade-s          #+#    #+#             */
/*   Updated: 2022/10/17 21:22:20 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_printf_specifier(char specifier, va_list args)
{
	int	counter;

	counter = 0;
	if (specifier == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		counter = ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		counter = ft_putptr(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		counter = ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		counter = ft_putunbr(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		counter = ft_puthexa(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		counter = ft_putchar('%');
	else
		counter = -1;
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		aux;

	va_start(args, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			aux = ft_printf_specifier(*format, args);
			if (aux == -1)
			{
				counter += write(1, "%", 1) + ft_putstr((char *)format);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:10:33 by lucade-s          #+#    #+#             */
/*   Updated: 2023/06/21 20:44:00 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_specifier(const char *specifier, va_list args)
{
	int	counter;

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
	return (counter);
}

static int	ft_verification(const char **format, int *aux, va_list args)
{
	int		counter;
	int		aux2;
	char	*c;

	counter = 0;
	c = &((char *)*format)[*aux - 1];
	if (*aux % 2 == 0 || ft_strchr("cspdiuxX", *c))
		aux2 = ft_printf_specifier(*format, args);
	else
	{
		counter += ft_putstr((char *)(*format - 1));
		write(1, "\nError: no valid specifier found.\n", 34);
		*aux = -1;
		return (counter);
	}
	counter += aux2;
	return (counter);
}

static int	ft_isnull(const char *format)
{
	if (!format)
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		aux;

	counter = ft_isnull(format);
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			aux = 0;
			while (format[aux] == '%')
				aux++;
			format++;
			counter += ft_verification(&format, &aux, args);
			if (aux == -1)
				return (counter);
		}
		else
			counter += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (counter);
}

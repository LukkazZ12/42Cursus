/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:10:33 by lucade-s          #+#    #+#             */
/*   Updated: 2022/10/18 20:37:55 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag(const char *flag, va_list args, int *counter)
{
	int				integer;
	unsigned int	unsinteger;
	char			aux_flag;

	aux_flag = *flag;
	while (*flag == aux_flag)
		flag++;
	if ((aux_flag == ' ' || aux_flag == '+') && (*flag == 'd' || *flag == 'i'))
	{
		integer = va_arg(args, int);
		if (integer >= 0)
			*counter = write(1, &aux_flag, 1) + ft_putnbr(integer);
		else
			*counter = ft_putnbr(integer);
	}
	else if (aux_flag == '#' && (*flag == 'x' || *flag == 'X'))
	{
		unsinteger = va_arg(args, unsigned int);
		if (unsinteger != 0)
			*counter = write(1, "0", 1) + write(1, flag, 1);
		*counter += ft_puthexa(unsinteger, *flag);
	}
	else
		*counter = -1;
}

static int	ft_printf_spec_flag(const char *spec_flag, va_list args)
{
	int	counter;

	counter = 0;
	if (*spec_flag == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (*spec_flag == 's')
		counter = ft_putstr(va_arg(args, char *));
	else if (*spec_flag == 'p')
		counter = ft_putptr(va_arg(args, unsigned long));
	else if (*spec_flag == 'd' || *spec_flag == 'i')
		counter = ft_putnbr(va_arg(args, int));
	else if (*spec_flag == 'u')
		counter = ft_putunbr(va_arg(args, unsigned int));
	else if (*spec_flag == 'x' || *spec_flag == 'X')
		counter = ft_puthexa(va_arg(args, unsigned int), *spec_flag);
	else if (*spec_flag == '%')
		counter = ft_putchar('%');
	else if (*spec_flag == ' ' || *spec_flag == '+' || *spec_flag == '#')
		ft_flag(spec_flag, args, &counter);
	return (counter);
}

static int	ft_verification(const char **format, int *aux, va_list args)
{
	int		counter;
	int		aux2;
	char	*c;

	counter = 0;
	c = &((char *)*format)[*aux - 1];
	if (*aux % 2 == 0 || ft_strchr("cspdiuxX +#", *c))
		aux2 = ft_printf_spec_flag(*format, args);
	else
		aux2 = -1;
	if (ft_strchr(" +#", *c) && *aux % 2 != 0 && aux2 != -1)
		while (ft_strchr(" +#", *(c++)))
			*format = c;
	if (aux2 == -1)
	{
		counter += ft_putstr((char *)(*format - 1));
		write(1, "\nError: no valid specifier or flag found.\n", 42);
		*aux = -1;
		return (counter);
	}
	counter += aux2;
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
	return (va_end(args), counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:11:26 by lucade-s          #+#    #+#             */
/*   Updated: 2022/10/18 16:29:26 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long n);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthexa(unsigned long n, char specifier);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *format, ...);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksanches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:40:36 by ksanches          #+#    #+#             */
/*   Updated: 2024/05/29 13:40:17 by ksanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "../minitalk.h"

int	ft_putnbr(int num, int *length)
{
	char			digit;
	unsigned int	n;

	n = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		n = -num;
		(*length)++;
	}
	else
		n = num;
	if (n > 9)
	{
		ft_putnbr(n / 10, length);
		ft_putnbr(n % 10, length);
	}
	else
	{
		digit = n + 48;
		(*length)++;
		write(1, &digit, 1);
	}
	return (*length);
}

int	ft_putnbr_unsigned(unsigned int n, int *length)
{
	char	a;

	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, length);
		ft_putnbr_unsigned(n % 10, length);
	}
	else
	{
		a = n + '0';
		(*length)++;
		write(1, &a, 1);
	}
	return (*length);
}

int	ft_printaddress(void *x, int *length, int flag)
{
	char				*hex;
	unsigned long long	n;

	n = (unsigned long long)x;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*length += 5;
		return (*length);
	}
	if (!flag)
	{
		write(1, "0x", 2);
		*length += 2;
		flag = 1;
	}
	hex = "0123456789abcdef";
	if (n >= 16)
		ft_printaddress((void *)(n / 16), length, flag);
	ft_putchar(hex[n % 16], length);
	return (*length);
}

int	ft_putchar(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
	return (*length);
}

int	ft_putstr(char *str, int *length)
{
	if (!str)
	{
		ft_putstr("(null)", length);
		return (*length);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*length)++;
	}
	return (*length);
}

int	ft_printhexa(unsigned int n, int *length, char type)
{
	char	*hex;

	if (type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_printhexa(n / 16, length, type);
	ft_putchar(hex[n % 16], length);
	return (*length);
}

int	format_handler(const char *format, va_list args, int *length)
{
	if (format[1] == 'c')
		return (ft_putchar(va_arg(args, int), length));
	else if (format[1] == 's')
		return (ft_putstr(va_arg(args, char *), length));
	else if (format[1] == 'p')
		return (ft_printaddress(va_arg(args, void *), length, 0));
	else if (format[1] == 'd' || format[1] == 'i')
		return (ft_putnbr(va_arg(args, int), length));
	else if (format[1] == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int), length));
	else if (format[1] == 'x' || format[1] == 'X')
		return (ft_printhexa(va_arg(args, int), length, format[1]));
	else if (format[1] == '%')
		return (ft_putchar('%', length));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format_handler(&format[i++], args, &length) == -1)
				return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
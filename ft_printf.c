/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zben-oma <zben-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:05:07 by zben-oma          #+#    #+#             */
/*   Updated: 2024/11/25 12:37:26 by zben-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	counter_writer(char *format, va_list args, size_t count, int i)
{
	if (format[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		count += ft_putaddress(va_arg(args, void *));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format[i] == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				if (ft_strchr("cspdiuxX", format[++i]))
					count = counter_writer((char *)format, args, count, i);
				else if (format[i] == '%')
					count += ft_putchar('%');
			}
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return ((int)count);
}

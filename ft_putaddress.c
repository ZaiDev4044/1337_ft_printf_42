/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zben-oma <zben-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:27:11 by zben-oma          #+#    #+#             */
/*   Updated: 2024/11/25 12:02:01 by zben-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putptr_base(unsigned long long n, char *base)
{
	size_t	len;
	size_t	count;

	count = 0;
	len = ft_strlen(base);
	if (len < 2)
		return (-1);
	if (n < len)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_putptr_base((n / len), base);
		count += ft_putchar(base[n % len]);
	}
	return (count);
}

size_t	ft_putaddress(void *ptr)
{
	size_t	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putptr_base((unsigned long long)ptr, "0123456789abcdef");
	return (count);
}

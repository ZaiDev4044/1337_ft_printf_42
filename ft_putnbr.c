/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zben-oma <zben-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:57:15 by zben-oma          #+#    #+#             */
/*   Updated: 2024/11/15 13:08:36 by zben-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(int n)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	if (n < 10)
		count += ft_putchar(n + 48);
	else if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + 48);
	}
	return (count);
}

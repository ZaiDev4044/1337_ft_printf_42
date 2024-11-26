/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zben-oma <zben-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:53:33 by zben-oma          #+#    #+#             */
/*   Updated: 2024/11/15 13:08:22 by zben-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(unsigned int n, char *base)
{
	unsigned int	len;
	size_t			count;

	count = 0;
	len = ft_strlen(base);
	if (len < 2)
		return (-1);
	if (n < (unsigned int)len)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_putnbr_base((n / len), base);
		count += ft_putchar(base[n % len]);
	}
	return (count);
}

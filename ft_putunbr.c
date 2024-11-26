/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zben-oma <zben-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:26:00 by zben-oma          #+#    #+#             */
/*   Updated: 2024/11/15 13:03:32 by zben-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunbr(unsigned int n)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (n < 10)
		count += ft_putchar(n + 48);
	else if (n >= 10)
	{
		count += ft_putunbr(n / 10);
		count += ft_putchar((n % 10) + 48);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zben-oma <zben-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:17:10 by zben-oma          #+#    #+#             */
/*   Updated: 2024/11/25 11:41:46 by zben-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
size_t	ft_putnbr(int n);
size_t	ft_putnbr_base(unsigned int n, char *base);
size_t	ft_putunbr(unsigned int n);
size_t	ft_putaddress(void *ptr);
char	*ft_strchr(const char *s, int c);
#endif

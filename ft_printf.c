/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoo-lee <yoo-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:32:46 by yoo-lee           #+#    #+#             */
/*   Updated: 2022/02/26 20:00:56 by yoo-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flags(const char *ptr, va_list ap)
{
	if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u')
	{
		if (*ptr == 'u')
			return (ft_d(va_arg(ap, unsigned int)));
		else
			return (ft_d(va_arg(ap, int)));
	}
	else if (*ptr == 'x' || *ptr == 'X' || *ptr == 'p')
	{
		if (*ptr == 'x' || *ptr == 'X')
			return (ft_hex(va_arg(ap, unsigned int), ptr));
		else
			return (ft_pointer(va_arg(ap, unsigned long int)));
	}
	else if (*ptr == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (*ptr == 's')
		return (ft_string(va_arg(ap, char *)));
	else if (*ptr == '%')
	{
		write(1, ptr, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		c;
	int		num;

	c = -1;
	num = 0;
	va_start(ap, fmt);
	while (fmt[++c])
	{
		if (fmt[c] == '%')
		{
			c += 1;
			num += ft_flags(&fmt[c], ap);
		}
		else
		{
			write(1, &fmt[c], 1);
			num++;
		}
	}
	va_end(ap);
	return (num);
}

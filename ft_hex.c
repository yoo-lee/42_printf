/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoo-lee <yoo-lee@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:32:37 by yoo-lee           #+#    #+#             */
/*   Updated: 2022/02/24 14:37:32 by yoo-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int num, const char *type)
{
	char			*base;
	char			new_num;
	static int		c;

	base = "0123456789abcdef";
	c = 0;
	if (num >= 16)
		ft_hex(num / 16, type);
	if (*type == 'x')
		new_num = base[num % 16];
	else if (*type == 'X')
	{
		if ((base[num % 16] >= 'A' && base[num % 16] <= 'Z') || \
		(base[num % 16] >= 'a' && base[num % 16] <= 'z'))
			new_num = ((base[num % 16]) - 32);
		else
			new_num = base[num % 16];
	}
	write(1, &new_num, 1);
	c++;
	return (c);
}

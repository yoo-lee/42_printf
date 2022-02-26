/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoo-lee <yoo-lee@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:32:31 by yoo-lee           #+#    #+#             */
/*   Updated: 2022/02/25 18:37:41 by yoo-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d(unsigned long int num)
{
	char	*res;
	int		counter;

	res = ft_itoa(num);
	ft_putstr_fd(res, 1);
	counter = ft_strlen(res);
	free(res);
	return (counter);
}

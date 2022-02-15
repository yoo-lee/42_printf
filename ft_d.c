#include "ft_printf.h"

int	ft_decimal(unsigned long int num)
{
	char	*res;
	int		counter;

	res = ft_itoa(num);
	ft_putstr_fd(res, 1);
	counter = ft_strlen(res);
	free(res);
	return (counter);
}
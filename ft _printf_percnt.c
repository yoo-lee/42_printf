#include "ft_percent.h"

size_t ft_printf_percent(size_t write_len)
{
	ft_putchar('%');
	return(++write_len);
}
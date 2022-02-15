int ft_printf(const char *fmt, ...)

#include "ft_printf.h"

static size_t	ft_flags(const char *format,
	va_list *ap, size_t write_len)
{
	if (*format == 'c')
		write_len = ft_printf_c(ap, write_len);
	else if (*format == 's')
		write_len = ft_printf_s(ap, write_len);
	else if (*format == 'p')
		write_len = ft_printf_p(ap, write_len);
	else if (*format == 'd' || *format == 'i')
		write_len = ft_printf_di(ap, write_len);
	else if (*format == 'u')
		write_len = ft_printf_u(ap, write_len);
	else if (*format == 'x')
		write_len = ft_printf_lower_x(ap, write_len);
	else if (*format == 'X')
		write_len = ft_printf_upper_x(ap, write_len);
	else if (*format == '%')
		write_len = ft_printf_percent(write_len);
	return (write_len);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int c;
	int num;

	c = -1;
	num = 0;
	va_start(ap, fmt);
	while (format[++c])
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
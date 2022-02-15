#include "ft_printf.h"

#include "ft_printf.h"

static size_t	ft_printf_converted_str(const char *format,
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

static int	ft_printf_helper(const char *format, va_list *ap)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			length = convert_to_str(format, ap, i, length);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			length++;
		}
	}
	return ((int)length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_printf_helper(format, &ap);
	va_end(ap);
	return (ret);
}
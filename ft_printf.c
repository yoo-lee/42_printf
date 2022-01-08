#include "ft_printf.h"

int convert_to_str(const char *fmt, va_list *ap, int i, int length)
{
	i++;
	if (fmt[i] == 'c')
	length = ft_putchar_c();
	
	{
		length = ft_putchar(va_arg(*ap, int));
	}
	return(length);
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

int main(void)
{
	ft_printf("%c", 'a');
	return(0);
}
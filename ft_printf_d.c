#include <stdio.h>
#include <stdlib.h>


size_t ft_printf_di(va_list *ap, size_t write_len)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));//何故itoaが必要なのか？
	if (num = NULL)
		return (ERROR);
	ft_putstr(num);
	write_len += ft_strlen_s(num)
	ft_free_s(void **)&num)
	return (write_len);
}

int main(void)
{
	ft_printf_di(2, 1234);
	printf("%d", 1234);
	return 0;
}
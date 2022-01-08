
size_t	ft_printf_s(va_list *ap, size_t write_len)
{
	char	*str;
	size_t	str_len;

	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		write_len += ft_strlen_s("(null)");
		return (write_len);
	}
	str_len = ft_strlen_s(str);
	if (write_len + str_len >= INT_MAX)
		return (ERROR);
	ft_putstr(str);
	write_len += str_len;
	return (write_len);
}



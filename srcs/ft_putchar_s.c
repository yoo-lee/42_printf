size_t  ft_printf_s (va_list *ap, size_t write_len )
{
	char *str;
	size_t str_len;
	
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		write_len += ft_strlen_s("(null)")
	}
}
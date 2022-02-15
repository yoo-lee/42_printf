#include "ft_printf.h"

int	ft_pointer(unsigned long int num)
{
	char			*base;
	char			new_num;
	static int		c;

	if (!num && !IS_MACOS)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	base = "0123456789abcdef";
	c = 0;
	if (num >= 16)
		ft_pointer(num / 16);
	if (!c)
	{
		write (1, "0x", 2);
		c += 2;
	}
	new_num = base[num % 16];
	write(1, &new_num, 1);
	c++;
	return (c);
}
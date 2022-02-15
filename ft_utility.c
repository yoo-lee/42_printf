#include "ft_printf.h"

static int	ft_nelements(long int num)
{
	int	c;

	c = 0;
	if (num == 0)
		c += 1;
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(long int n)
{
	int			el;
	int			flag;
	char		*str;
	long int	num;

	flag = 0;
	num = n;
	if (num < 0)
	{
		flag = 1;
		num *= -1;
	}
	el = ft_nelements(num) + flag;
	str = (char *)malloc(el + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (flag > 0)
		str[0] = '-';
	str[el] = '\0';
	while (el-- > flag)
	{
		str[el] = ((num % 10) + '0');
		num = num / 10;
	}
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
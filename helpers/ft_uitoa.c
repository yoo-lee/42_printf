#include "libft.h"

static size_t	count_digits(unsigned int n)
{
	size_t		digits_count;

	digits_count = 0;
	while (n > 0)
	{
		digits_count++;
		n /= 10;
	}
	return (digits_count);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	digits_count;
	char	*num;

	if (n == 0)
		return (ft_strdup("0"));
	digits_count = count_digits(n);
	num = (char *)ft_calloc(digits_count + 1, sizeof(char));
	if (num == NULL)
		return (NULL);
	while (digits_count-- > 0)
	{
		num[digits_count] = "9876543210123456789"[n % 10 + 9];
		n /= 10;
	}
	return (num);
}

int main ()
{
	ft_uitoa(6);
	return (0);
}
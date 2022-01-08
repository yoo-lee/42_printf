#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	if (n == 0)
		return (ft_strdup("0"));// 
	if (ft_strcmp(base, "0123456789") == 0)//同じ文字だったら、返り値　０ baseが同じ文字数が前提
		return (ft_itoa(n));
	return (ft_uitoa_base((unsigned int)n, base));//uitoa ーが来た場合などのビット演算前提。
}

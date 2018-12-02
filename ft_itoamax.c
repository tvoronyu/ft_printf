#include "ft_printf.h"

void	itoa_isnegative(intmax_t *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_itoamax(intmax_t n)
{
	intmax_t	tmpn;
	int			len;
	int			negative;
	char		*str;

	if (n == INTMAX_MIN)
		return (ft_strdup("-9223372036854775808"));
	tmpn = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
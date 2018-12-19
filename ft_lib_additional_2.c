#include "ft_printf.h"

int		ft_str_chr_all(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] == c)
		++i;
	if (str[i])
		return (0);
	return (1);
}

int		ft_lenchr(const char *s, int *start, char c)
{
	int i;

	i = *start;
	while (s[*start])
		if (s[(*start)++] == c)
			return (*start - i - 1);
	return (*start - i);
}

int		ft_len_chr_str(const char *s, int start, char *sub)
{
	int i;
	int len;

	len = ft_strlen(sub);
	while (s[start])
	{
		i = len;
		while (i--)
			if (s[start] == sub[i])
				return (start);
		++start;
	}
	return (-1);
}

int		ft_minus_2(int *pow)
{
	if (*pow < 0)
	{
		*pow = -(*pow);
		return ('-');
	}
	return ('+');
}

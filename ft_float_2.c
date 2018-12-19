#include "ft_printf.h"

int		ft_float_minus(long double *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (1);
	}
	return (0);
}

char	*ft_float_add_minus(char *str, list *ptr)
{
	char	*new;
	int		i;

	new = ft_strnew(++ptr->ptr_parse->len);
	new[0] = '-';
	i = 0;
	while (++i < ptr->ptr_parse->len)
		new[i] = str[i - 1];
	ft_strdel(&str);
	return (new);
}

char	*ft_float_binary(unsigned long *ptr)
{
	char	*str;
	int		len;

	len = 64;
	str = ft_strnew(len);
	while (len)
	{
		str[--len] = *ptr % 2 + '0';
		*ptr /= 2;
	}
	return (str);
}

int		ft_float_dot(list *ptr)
{
	if (ptr->ptr_parse->precision_field == -1)
		ptr->ptr_parse->precision_field = 6;
	if (ptr->ptr_parse->precision_field)
		return (1);
	return (0);
}

char	*ft_float_add_exponent(char *str, list *ptr, int count, char type)
{
	int		len;
	int		i;
	char	*new;

	if (ptr->ptr_parse->flag_hash)
		if (ft_char_index(str, '.') == -1)
			str = ft_str_join_char_free(str, ptr->ptr_parse->len++, '.');
	if (count > 99 || count < -99)
		len = 3;
	else
		len = 2;
	new = ft_strnew(len + ptr->ptr_parse->len + 2);
	i = -1;
	while (++i < ptr->ptr_parse->len)
		new[i] = str[i];
	ptr->ptr_parse->len += 2 + len;
	new[i++] = type;
	new[i++] = ft_minus_2(&count);
	while (len--)
	{
		new[i + len] = count % 10 + '0';
		count /= 10;
	}
	ft_strdel(&str);
	return (new);
}

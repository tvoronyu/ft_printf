#include "ft_printf.h"

char	*ft_round_float_2(char *str, list *ptr)
{
	int		len;
	char	*new;

	len = ptr->ptr_parse->len;
	new = ft_strnew(++ptr->ptr_parse->len);
	while (len--)
		new[len + 1] = str[len];
	new[0] = '1';
	ft_strdel(&str);
	return (new);
}

char	*ft_round_float(char *str, list *ptr)
{
	int		len;
	int		fl;

	if (ptr->ptr_parse->len == 0)
		return (str);
	len = ptr->ptr_parse->len;
	fl = 1;
	while (len-- && fl)
	{
		if (str[len] == '.')
			continue ;
		++str[len];
		if (str[len] == '9' + 1)
			str[len] = '0';
		else
			fl = 0;
	}
	if (fl)
		return (ft_round_float_2(str, ptr));
	return (str);
}

#include "ft_printf.h"

char	*ft_str_join_free(char *s1, char *s2, int len1, int len2)
{
	char	*str;
	int		len;

	len = len1 + len2;
	str = ft_strnew(len);
	while (len2--)
		str[--len] = s2[len2];
	while (len1--)
		str[--len] = s1[len1];
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}

char	*ft_str_join_char_free(char *s1, int len, char c)
{
	char	*str;

	str = ft_strnew(len + 1);
	str[len] = c;
	while (len--)
		str[len] = s1[len];
	ft_strdel(&s1);
	return (str);
}

void	ft_my_strcat(list *ptr, char *s1, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (ptr->ptr_parse->len_full == BUFF_SIZE)
		{
			write(1, ptr->ptr_parse->str_full, BUFF_SIZE);
			ptr->ptr_parse->len_full = 0;
		}
		ptr->ptr_parse->str_full[ptr->ptr_parse->len_full++] = s1[i];
	}
	ft_strdel(&s1);
}

void	ft_expand(char **form, list *ptr)
{
	int		i;

	i = -1;
	while ((*form)[++i])
	{
		if ((*form)[i] == '%')
			break ;
		if (ptr->ptr_parse->len_full == BUFF_SIZE)
		{
			write(1, &(ptr->ptr_parse->str_full), BUFF_SIZE);
			ptr->ptr_parse->len_full = 0;
		}
		ptr->ptr_parse->str_full[ptr->ptr_parse->len_full++] = (*form)[i];
	}
	*form += i;
}

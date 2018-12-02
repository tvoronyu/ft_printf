#include "ft_printf.h"

int		fz(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] != '0')
			return (1);
		counter++;
	}
	return (0);
}

int		ft_ifhash(char *str, list *ptr)
{
	int		counter;
	char	*tmp;

	tmp = NULL;
	if (*ptr->form == 'x' && fz(str))
		tmp = ft_strjoin("0x", str);
	if (*ptr->form == 'X' && fz(str))
		tmp = ft_strjoin("0X", str);
	if ((*ptr->form == 'O' || *ptr->form == 'o') && fz(str))
		tmp = ft_strjoin("0", str);
	if (tmp)
	{
		counter = ft_parsetype(tmp, ptr);
		ft_strdel(&tmp);
	}
	else
		counter = ft_parsetype(str, ptr);
	if (ft_strlen(str))
		ft_strdel(&str);
	return (counter);
}

int		ft_crutch(list *ptr, char *new_str)
{
	int counter;

	if (ptr->ptr_parse->flag_hash)
		counter = ft_ifhash(new_str, ptr);
	else
	{
		counter = ft_parsetype(new_str, ptr);
		free(new_str);
	}
	return (counter);
}

int		ft_makeaccept(char *old, list *ptr)
{
	char	*new_str;
	size_t	len;
	int		counter;
	char	*tmp;

	len = ft_strlen(old);
	if (old[0] == '-')
	{
		len--;
		ptr->ptr_parse->flag_dot++;
	}
	new_str = ft_memalloc(ptr->ptr_parse->flag_dot);
	ft_memset(new_str, '0', ptr->ptr_parse->flag_dot - len);
	if (old[0] == '-')
	{
		new_str[0] = '-';
		old++;
	}
	tmp = ft_strcat(new_str, old);
	counter = ft_crutch(ptr, tmp);
	return (counter);
}

char	*ft_editline(int *len, list *ptr)
{
	if (*len == 1 && ptr->ptr_parse->tmp[0] == '0' &&
		ptr->ptr_parse->flag_dot == -1 && (*ptr->form == 'x' || *ptr->form == 'X'))
	{
		// free(str);
		return ("");
	}
	if (*len == 1 && ptr->ptr_parse->tmp[0] == '0' && ptr->ptr_parse->flag_dot == -1 && !ptr->ptr_parse->flag_hash)
	{
		// free(str);
		return ("");
	}
	if (ptr->ptr_parse->tmp[0] == '-')
		*len -= 1;
	return (str);
}

int		ft_makeprintbl(list *ptr)
{
	int len;
	int counter;
	char *str;

	counter = 0;
	len = ft_strlen(ptr->ptr_parse->tmp);
	if (ptr->ptr_parse->tmp)
	{
		str = ft_editline(&len, ptr);
		if (ptr->ptr_parse->flag_hash && ptr->ptr_parse->flag_dot > 0 && (*ptr->form == 'o' || *ptr->form == 'O') && fz(str))
			ptr->ptr_parse->flag_dot--;
		if (len < ptr->ptr_parse->flag_dot)
		{
			counter = ft_makeaccept(str, ptr);
			free(str);
		}
		else if (full[0][3])
			counter = ft_ifhash(t, str, full);
	}
	if (!counter)
	{
		counter = ft_parsetype(str, full, t);
		if (ft_strlen(str))
			ft_strdel(&str);
	}
	return (counter);
}

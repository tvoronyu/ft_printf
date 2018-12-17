#include "ft_printf.h"

void	ft_makewidth_is_width(list *ptr, char *tmp, char *tmp_2, long long i)
{
	if ((i = ptr->ptr_parse->flag_width - ft_strlen(ptr->tmp)) > 0)
	{
		tmp = ft_strnew(i);
		ft_memset(tmp, ' ', i);
		if (ptr->ptr_parse->flag_minus)
			tmp_2 = ft_strjoin(ptr->tmp, tmp);
		else
			tmp_2 = ft_strjoin(tmp, ptr->tmp);
		free(tmp);
		free(ptr->tmp);
		ptr->tmp = tmp_2;
	}
}

void	ft_width_help_1(list *ptr, char *tmp, char *tmp_2, long long i)
{
	if (ptr->ptr_parse->flag_zero && !ptr->ptr_parse->flag_minus)
	{
		tmp = ft_strnew(i);
		ft_memset(tmp, '0', i);
		if (ptr->tmp[0] == '-')
			tmp_2 = ft_strjoin("-", ft_strjoin(tmp, ptr->tmp + 1));
		else if (ptr->tmp[0] == '+')
			tmp_2 = ft_strjoin("+", ft_strjoin(tmp, ptr->tmp + 1));
		else
			tmp_2 = ft_strjoin(tmp, ptr->tmp);
	}
	else
	{
		tmp = ft_strnew(i);
		ft_memset(tmp, ' ', i);
		if (ptr->ptr_parse->flag_minus)
			tmp_2 = ft_strjoin(ptr->tmp, tmp);
		else
			tmp_2 = ft_strjoin(tmp, ptr->tmp);
	}
	free(tmp);
	free(ptr->tmp);
	ptr->tmp = tmp_2;
}

void	ft_makewidth(list *ptr)
{
	long long	i;
	char		*tmp;
	char		*tmp_2;

	i = 0;
	if (ptr->ptr_parse->flag_dot != 0)
		ft_makewidth_is_width(ptr, tmp, tmp_2, i);
	else
	{
		if ((i = ptr->ptr_parse->flag_width - ft_strlen(ptr->tmp)) > 0)
			ft_width_help_1(ptr, tmp, tmp_2, i);
	}
	if (!ptr->ptr_parse->flag_dot && !ptr->ptr_parse->flag_width
		&& ptr->ptr_parse->flag_space
		&& !ptr->ptr_parse->flag_plus
		&& !ptr->ptr_parse->flag_minus
		&& ptr->tmp[0] != '-')
	{
		tmp = ft_strjoin(" ", ptr->tmp);
		free(ptr->tmp);
		ptr->tmp = tmp;
	}
}
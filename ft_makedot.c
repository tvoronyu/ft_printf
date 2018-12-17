#include "ft_printf.h"

void	help_dot_2(list *ptr, char *tmp, char *tmp_2, long long	i)
{
	if ((i = ptr->ptr_parse->flag_dot - ft_strlen(ptr->tmp)) > 0)
	{
		tmp = ft_strnew(i);
		ft_memset(tmp, '0', i);
		tmp_2 = ft_strjoin("+", ft_strjoin(tmp, ptr->tmp));
		free(tmp);
		free(ptr->tmp);
		ptr->tmp = tmp_2;
	}
	else
	{
		tmp_2 = ft_strjoin("+", ptr->tmp);
		free(ptr->tmp);
		ptr->tmp = tmp_2;
	}
}

void	help_dot_3(list *ptr, char *tmp, char *tmp_2, long long	i)
{
	if ((i = ptr->ptr_parse->flag_dot - ft_strlen(ptr->tmp)) > 0)
	{
		tmp = ft_strnew(i);
		ft_memset(tmp, '0', i);
		tmp_2 = ft_strjoin(tmp, ptr->tmp);
		free(tmp);
		free(ptr->tmp);
		ptr->tmp = tmp_2;
	}
}

void	help_dot(list *ptr, char *tmp, char *tmp_2, long long i)
{
	if (ptr->tmp[0] == '-')
		{
			if ((i = ptr->ptr_parse->flag_dot - (ft_strlen(ptr->tmp) - 1)) > 0)
			{
				tmp = ft_strnew(i);
				ft_memset(tmp, '0', i);
				tmp_2 = ft_strjoin("-", ft_strjoin(tmp, ptr->tmp + 1));
				free(tmp);
				free(ptr->tmp);
				ptr->tmp = tmp_2;
			}
		}
		else if (ptr->ptr_parse->flag_plus)
			help_dot_2(ptr, NULL, NULL, i);
		else
			help_dot_3(ptr, NULL, NULL, i);
}

void	help_dot_plus(list *ptr, char *tmp_2)
{
	if (ptr->tmp[0] != '-')
	{
		tmp_2 = ft_strjoin("+", ptr->tmp);
		free(ptr->tmp);
		ptr->tmp = tmp_2;
	}
}

void	ft_makedot(list *ptr)
{
	long long	i;

	i = 0;
	if (ptr->ptr_parse->flag_dot > 0)
		help_dot(ptr, NULL, NULL, i);
	else if (ptr->ptr_parse->flag_plus)
		help_dot_plus(ptr, NULL);
	else if (ptr->ptr_parse->flag_dot == -1)
	{
		if (ptr->tmp[0] == '0')
		{
			free(ptr->tmp);
			ptr->tmp = ft_strjoin("", "\0");
		}
	}
	ft_makewidth(ptr);
}
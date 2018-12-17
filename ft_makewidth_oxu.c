#include "ft_printf.h"

void	ft_make_hash(list *ptr)
{
	char *str;
	// ft_putendl(ptr->tmp);
	if (ptr->ptr_parse->flag_hash)
	{
		if (*ptr->form == 'x')
		{
			str = ft_strjoin("0x", ptr->tmp);
			free(ptr->tmp);
			ptr->tmp = str;
		}
		if (*ptr->form == 'X')
		{
			str = ft_strjoin("0X", ptr->tmp);
			free(ptr->tmp);
			ptr->tmp = str;
		}
		if (*ptr->form == 'o')
		{
			str = ft_strjoin("0", ptr->tmp);
			free(ptr->tmp);
			ptr->tmp = str;
		}
	}
}

void	ft_makewidth_oxu(list *ptr)
{
	long long	i;
	char		*tmp;
	char		*tmp_2;

	i = 0;
	if (ptr->ptr_parse->flag_dot != 0)
	{
		ft_make_hash(ptr);
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
	else
	{
		if ((i = ptr->ptr_parse->flag_width - ft_strlen(ptr->tmp)) > 0)
		{
			if (ptr->ptr_parse->flag_zero)
			{
				if (ptr->ptr_parse->flag_hash)
				{
					if (*ptr->form == 'x' || *ptr->form == 'X')
						i -= 2;
					if (*ptr->form == 'o')
						i -= 1;
				}
				if (i > 0)
				{
					tmp = ft_strnew(i);
					ft_memset(tmp, '0', i);
					if (ptr->ptr_parse->flag_minus)
					{
						ft_memset(tmp, ' ', i);
						tmp_2 = ft_strjoin(ptr->tmp, tmp);
					}
					else
						tmp_2 = ft_strjoin(tmp, ptr->tmp);
					free(tmp);
					free(ptr->tmp);
					ptr->tmp = tmp_2;
				}
				ft_make_hash(ptr);
			}
			else if (!ptr->ptr_parse->flag_zero)
			{
				if (ptr->ptr_parse->flag_hash)
				{
					if (*ptr->form == 'x' || *ptr->form == 'X')
						i -= 2;
					if (*ptr->form == 'o')
						i -= 1;
				}
				if (i > 0)
				{
					tmp = ft_strnew(i);
					ft_memset(tmp, ' ', i);
					ft_make_hash(ptr);
					if (ptr->ptr_parse->flag_minus)
						tmp_2 = ft_strjoin(ptr->tmp, tmp);
					else
						tmp_2 = ft_strjoin(tmp, ptr->tmp);
					free(tmp);
					free(ptr->tmp);
					ptr->tmp = tmp_2;
				}
			}
		}
		else
			ft_make_hash(ptr);
	}
}
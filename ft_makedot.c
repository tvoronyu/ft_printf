#include "ft_printf.h"

void	ft_makedot(list *ptr)
{
	char	*str;
	int 	i;

	i = 0;
	if (ptr->ptr_parse->flag_dot && ptr->ptr_parse->flag_dot != 0 && ptr->ptr_parse->flag_dot != -1)
	{
		if (*ptr->ptr_parse->tmp == '-')
		{
			if (ptr->ptr_parse->flag_dot >= ft_strlen(ptr->ptr_parse->tmp))
			{
				str = ft_strnew(ptr->ptr_parse->flag_dot - ft_strlen(ptr->ptr_parse->tmp) + 1);
				str[0] = '-';
				while ((ptr->ptr_parse->flag_dot - ft_strlen(ptr->ptr_parse->tmp)) >= i++)
				{
					str[i] = '0';
					// i++;
				}
				ptr->tmp = ft_strjoin(str, ptr->ptr_parse->tmp + 1);
				free(str);
				str = ptr->tmp;
				ft_copy(ptr);
				free(str);
			}
		}
		else
		{
			if (ptr->ptr_parse->flag_dot >= ft_strlen(ptr->ptr_parse->tmp))
			{
				str = ft_strnew(ptr->ptr_parse->flag_dot - ft_strlen(ptr->ptr_parse->tmp));
				while ((ptr->ptr_parse->flag_dot - ft_strlen(ptr->ptr_parse->tmp)) > i)
				{
					str[i] = '0';
					i++;
				}
				ptr->tmp = ft_strjoin(str, ptr->ptr_parse->tmp);
				free(str);
				str = ptr->tmp;
				ft_copy(ptr);
				free(str);
			}
		}
	}
	if (ptr->ptr_parse->flag_width > ptr->ptr_parse->flag_dot)
	{
		if (*ptr->form == 'd' || *ptr->form == 'i')
			ft_makewidth(ptr);
		else
			ft_makewidth_2(ptr);
	}
	// else if (ptr->ptr_parse->flag_dot == -1)
	// {
	// 	ft_putendl("zero");
	// 	ft_putnbr(ptr->ptr_parse->flag_dot);
	// }
	// else if (ptr->ptr_parse->flag_dot == 0)
	// {
	// 	ft_putendl("none");
	// 	ft_putnbr(ptr->ptr_parse->flag_dot);
	// }
}
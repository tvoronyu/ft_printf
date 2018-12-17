#include "ft_printf.h"

void	ft_makedot_oxu(list *ptr)
{
	long long	i;
	char		*tmp;
	char		*tmp_2;

	i = 0;
	if (ptr->ptr_parse->flag_dot != 0)
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
	if (ptr->ptr_parse->flag_dot == 0 && ptr->tmp[0] == '0' && *ptr->form != 'o')
		ptr->ptr_parse->flag_hash = 0;
	if (ptr->ptr_parse->flag_dot == -1 && ptr->tmp[0] == '0')
	{
		free(ptr->tmp);
		ptr->tmp = ft_strjoin("", "\0");
		if (*ptr->form != 'o')
			ptr->ptr_parse->flag_hash = 0;
	}
	ft_makewidth_oxu(ptr);
}
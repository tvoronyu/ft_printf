#include "ft_printf.h"

void	ft_find_size(list *ptr)
{
	char	base[] = "jzlhL";
	int		count;
	char	*symbol;

	count = 0;
	while (base[count] != '\0')
	{
		if ((symbol = ft_strchr(ptr->str, base[count])))
		{
			if (*symbol == 'j')
				ptr->ptr_parse->flag_size = 1;
			else if (*symbol == 'z')
				ptr->ptr_parse->flag_size = 2;
			else if (*symbol == 'l' && ft_strchr(symbol + 1, 'l'))
				ptr->ptr_parse->flag_size = 3;
			else if (*symbol == 'l' && !ft_strchr((symbol + 1), 'l'))
				ptr->ptr_parse->flag_size = 4;
			else if (*symbol == 'h' && ft_strchr((symbol + 1), 'h'))
				ptr->ptr_parse->flag_size = 5;
			else if (*symbol == 'h' && !ft_strchr((symbol + 1), 'h'))
				ptr->ptr_parse->flag_size = 6;
			else if (*symbol == 'L')
				ptr->ptr_parse->flag_size = 7;
		}
		count++;
	}
}
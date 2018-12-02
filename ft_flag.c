#include "ft_printf.h"

int	ft_ifzero(char *format_str)
{
	int counter;
	int s_count;

	counter = 0;
	while (format_str[counter])
	{
		if (format_str[counter] == '0')
		{
			s_count = counter;
			while (format_str[s_count])
			{
				if ((format_str[s_count] <= '9' &&
					format_str[s_count] > '0') || format_str[s_count] == '.')
					break ;
				if (format_str[s_count] > '9' || format_str[s_count] < '0')
					return ('0');
				s_count--;
			}
			if (!format_str[s_count])
				return ('0');
		}
		counter++;
	}
	return (0);
}

void	ft_find_flag(list *ptr)
{
	if (ft_strchr(ptr->str, '+'))
		ptr->ptr_parse->flag_plus = '+';
	if (ft_strchr(ptr->str, '-'))
		ptr->ptr_parse->flag_minus = '-';
	if (ft_strchr(ptr->str, ' '))
		ptr->ptr_parse->flag_space = ' ';
	if (ft_strchr(ptr->str, '#'))
		ptr->ptr_parse->flag_hash = '#';
	ptr->ptr_parse->flag_zero = ft_ifzero(ptr->str);
}
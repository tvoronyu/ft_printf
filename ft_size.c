#include "ft_printf.h"

int	ft_find_size(list *ptr)
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
				return (1);
			else if (*symbol == 'z')
				return (2);
			else if (*symbol == 'l' && ft_strchr(symbol + 1, 'l'))
				return (3);
			else if (*symbol == 'l' && !ft_strchr((symbol + 1), 'l'))
				return (4);
			else if (*symbol == 'h' && ft_strchr((symbol + 1), 'h'))
				return (5);
			else if (*symbol == 'h' && !ft_strchr((symbol + 1), 'h'))
				return (6);
			else if (*symbol == 'L')
				return (7);
		}
		count++;
	}
	return (0);
}
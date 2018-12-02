#include "ft_printf.h"

void	ft_ifdigit(list *ptr)
{
	if (*(ptr->str - 1)== '.')
	{
		if (!ft_isdigit(*ptr->str))
			ptr->ptr_parse->flag_dot = -1;
		else
		{
			ptr->ptr_parse->flag_dot = ft_atoi(ptr->str);
			while (ft_isdigit(*ptr->str))
				ptr->str++;
			if (!ptr->ptr_parse->flag_dot)
				ptr->ptr_parse->flag_dot = -1;
		}
	}
	else
	{
		// ft_putendl(ptr->str);
		while (*ptr->str == '0')
		{
			ptr->ptr_parse->flag_zero = '0';
			ptr->str++;
		}
		// if (ft_isdigit(ptr->str))
			ptr->ptr_parse->flag_width = ft_atoi(ptr->str);
		// ft_putendl(ptr->str);
		while (ft_isdigit(*ptr->str))
			ptr->str++;
		if (!ptr->ptr_parse->flag_width)
			ptr->ptr_parse->flag_width = -1;
	}
	ptr->str++;
}

void	ft_modificator(list *ptr)
{
	char *str;

	str = ptr->str;
	// ft_putendl(ptr->str);
	while (*ptr->str != '\0')
	{
		if (*ptr->str == '*')
		{
			if (*(ptr->str - 1) == '.')
				ptr->ptr_parse->flag_dot = va_arg(ptr->args, int);
			else
				ptr->ptr_parse->flag_width = va_arg(ptr->args, int);
			ptr->str++;
		}
		else if ((ft_isdigit(*ptr->str) && *ptr->str != '0') || *(ptr->str - 1) == '.')
			ft_ifdigit(ptr);
		else
			ptr->str++;
	}
	ptr->str = str;
}
#include "ft_printf.h"

void	ft_makediff(list *ptr)
{
	char	symbol;
	size_t	counter;

	counter = 0;
	if (*ptr->form == 'c')
		ptr->buffer[ptr->count++] = va_arg(ptr->args, int);
	symbol = ' ';
	if (ptr->ptr_parse->flag_zero == '0' && ptr->ptr_parse->flag_space)
		symbol = '0';
	ptr->ptr_parse->flag_width--;
	// if (ptr->ptr_parse->flag_dot)
	// {
	// ft_putendl(ptr->form);

		while (counter++ < ptr->ptr_parse->flag_width)
			ptr->buffer[ptr->count++] = symbol;
		// if (*ptr->form == '%')
		// 	ptr->buffer[ptr->count++] = '%';

}

void	ft_makewidth_2(list *ptr)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ptr->ptr_parse->flag_width >= ft_strlen(ptr->ptr_parse->tmp))
	{
		if (ptr->ptr_parse->flag_minus)
		{
			str = ft_strnew(ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp));
			while ((ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp)) > i)
			{
				str[i] = ' ';
				i++;
			}
			ptr->tmp = ft_strjoin(ptr->ptr_parse->tmp, str);
			free(str);
			str = ptr->tmp;
			ft_copy(ptr);
			free(str);
		}
		else if (ptr->ptr_parse->flag_zero)
		{
			if (*ptr->ptr_parse->tmp == '-')
			{
				str = ft_strnew((ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp)) + 1);
				str[0] = '-';
				while ((ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp)) > i++)
					str[i] = '0';
				ptr->tmp = ft_strjoin(str, ptr->ptr_parse->tmp + 1);
			}
			else
			{
				str = ft_strnew(ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp));
				while ((ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp)) > i)
				{
					str[i] = '0';
					i++;
				}
				ptr->tmp = ft_strjoin(str, ptr->ptr_parse->tmp);
			}
			free(str);
			str = ptr->tmp;
			ft_copy(ptr);
			free(str);
		}
		else
		{
			str = ft_strnew(ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp));
			while ((ptr->ptr_parse->flag_width - ft_strlen(ptr->ptr_parse->tmp)) > i)
			{
				str[i] = ' ';
				i++;
			}
			ptr->tmp = ft_strjoin(str, ptr->ptr_parse->tmp);
			free(str);
			str = ptr->tmp;
			ft_copy(ptr);
			free(str);
		}
	}
	else
	{
		ptr->tmp = ptr->ptr_parse->tmp;
		ft_copy(ptr);
	}
	// free(ptr->ptr_parse->tmp);
}

void	ft_make_hash(list *ptr)
{
	char *str;

	if (ptr->ptr_parse->flag_hash)
	{
		if (*ptr->form == 'x' && *ptr->ptr_parse->tmp != '0')
		{
			str = ft_strjoin("0x", ptr->ptr_parse->tmp);
			free(ptr->ptr_parse->tmp);
			ptr->ptr_parse->tmp = str;
		}
		if (*ptr->form == 'X' && *ptr->ptr_parse->tmp != '0')
		{
			str = ft_strjoin("0X", ptr->ptr_parse->tmp);
			free(ptr->ptr_parse->tmp);
			ptr->ptr_parse->tmp = str;
		}
		if (*ptr->form == 'o' && *ptr->ptr_parse->tmp != '0')
		{
			str = ft_strjoin("0", ptr->ptr_parse->tmp);
			free(ptr->ptr_parse->tmp);
			ptr->ptr_parse->tmp = str;
		}
	}
	// free(ptr->tmp);
	ptr->tmp = ptr->ptr_parse->tmp;
}


void	ft_makestr(list *ptr)
{
	if ((ptr->tmp = va_arg(ptr->args, char*)))
		ft_copy(ptr);
}

void	ft_find_type(list *ptr)
{
	// if (*ptr->form == 'S' || (*ptr->form == 's' && ptr->ptr_parse->flag_size == 4))
	// 	ft_putchar('S');
	// else
	// {
		if (*ptr->form == 'd' || *ptr->form == 'i')
			preparetosize(ptr);
			// res += ft_makeprintbl(preparetosize(full[2][0], ar, t), full, t);
		else if (*ptr->form == 'o' || *ptr->form == 'u' || *ptr->form == 'x' || *ptr->form == 'X')
			upreparetosize(ptr);
		// 	ft_putchar('o');
		// 	// res += ft_makeprintbl(upreparetosize(full[2][0], ar, t), full, t);
		// else if (*ptr->form == 'C' || (*ptr->form == 'c' && ptr->ptr_parse->flag_size == 4))
		// 	ft_putchar('c');
		// 	// res += ft_makewprintbl(ft_makewchar(va_arg(ar, wchar_t)), full, t);
		// else if (*ptr->form == 'p')
		// 	ft_putchar('p');
		// 	// res += ft_makeptr(printmemory(ar), full, t);
		// else if (*ptr->form == 's')
		// 	ft_makestr(ptr);
		// // else if (*ptr->form == '%')
		// // 	ft_putchar('g');
		// else
		// 	ft_makediff(ptr);
	// }
	// return (res);
}
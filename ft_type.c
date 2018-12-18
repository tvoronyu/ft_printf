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

void	ft_makestr_dot(list *ptr)
{
	long long	i;
	// char		*tmp;
	// char		*tmp_2;

	i = 0;
	if (ptr->ptr_parse->flag_dot != 0)
	{
		// 
	}
}

void	ft_makestr(list *ptr)
{
	ptr->tmp = va_arg(ptr->args, char*);
	if (ptr->tmp == NULL)
		ptr->tmp = ft_strdup("(null)");
	else
		ft_makestr_dot(ptr);
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
		else if (*ptr->form == 's')
			ft_makestr(ptr);
		// // else if (*ptr->form == '%')
		// // 	ft_putchar('g');
		// else
		// 	ft_makediff(ptr);
	// }
	// return (res);
}
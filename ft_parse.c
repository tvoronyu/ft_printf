#include "ft_printf.h"

void	ft_parse(list *ptr)
{
	char *str;

	str = (ft_strsub(ptr->form_start, 0, ptr->form - ptr->form_start + 1));
	ptr->str = str;
	list_parse ptr_list[1];
	ft_bzero(ptr_list, sizeof(list_parse));
	ptr->ptr_parse = ptr_list;

	// ft_putendl(ptr->buffer);
	// ft_putendl(ptr->form);

	ft_find_flag(ptr);
// ft_putendl(ptr->str);
	ft_modificator(ptr);

	ft_find_size(ptr);

	// ft_putendl(ptr->str);

	// ft_putstr("Width -   ");
	// ft_putnbr(ptr->ptr_parse->flag_width);
	// ft_putstr("\nDot -     ");
	// ft_putnbr(ptr->ptr_parse->flag_dot);
	// ft_putstr("\nSize -    ");
	// ft_putnbr(ptr->ptr_parse->flag_size);
	// ft_putstr("\nSpace -   '");
	// ft_putchar(ptr->ptr_parse->flag_space);
	// ft_putstr("'\nPlus -     ");
	// ft_putchar(ptr->ptr_parse->flag_plus);
	// ft_putstr("\nMinus -    ");
	// ft_putchar(ptr->ptr_parse->flag_minus);
	// ft_putstr("\nZero -     ");
	// ft_putchar(ptr->ptr_parse->flag_zero);
	// ft_putstr("\nHash -     ");
	// ft_putchar(ptr->ptr_parse->flag_hash);
	// ft_putstr("\nType -     ");
	// ft_putchar(*ptr->form);
	// ft_putstr("\n");
	// ft_putendl("");
	ft_find_type(ptr);
	// ptr->str = ptr->tmp;
	ft_copy(ptr);
	// free(ptr->str);

	// ft_putnbr(ptr->ptr_parse->flag_width);

	// ft_putendl(ft_itoa(ptr->ptr_parse->flag_width));
	// ft_putendl(ft_itoa(ptr->ptr_parse->flag_dot));

	free(str);
}
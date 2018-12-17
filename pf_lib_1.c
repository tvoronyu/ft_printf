#include "ft_printf.h"

char	*my_itoa_basemax(uintmax_t num, size_t base, int is_bigger)
{
	char		*base_str;
	char		*str;
	uintmax_t	c_num;
	int			size;

	if (is_bigger)
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	c_num = num;
	size = 1;
	while (c_num > base - 1)
	{
		c_num /= base;
		size++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size--)
	{
		str[size] = base_str[num % base];
		num /= base;
	}
	// ft_putnbr(num);
	return (str);
}

void	makebase(list *ptr)
{
	if (*ptr->form == 'd' || *ptr->form == 'i')
		ptr->ptr_parse->tmp = ft_itoamax(ptr->ptr_parse->number);
	if (*ptr->form == 'o')
		ptr->ptr_parse->tmp = my_itoa_basemax(ptr->ptr_parse->unumber, 8, 0);
	if (*ptr->form == 'u')
		ptr->ptr_parse->tmp = my_itoa_basemax(ptr->ptr_parse->unumber, 10, 0);
	if (*ptr->form == 'x')
		ptr->ptr_parse->tmp = my_itoa_basemax(ptr->ptr_parse->unumber, 16, 0);
	if (*ptr->form == 'X')
		ptr->ptr_parse->tmp = my_itoa_basemax(ptr->ptr_parse->unumber, 16, 1);
}

void	upreparetosize(list *ptr)
{
	if (ptr->ptr_parse->flag_size == 1)
		ptr->ptr_parse->unumber = va_arg(ptr->args, uintmax_t);
	else if (ptr->ptr_parse->flag_size == 2)
		ptr->ptr_parse->unumber = va_arg(ptr->args, size_t);
	else if (ptr->ptr_parse->flag_size == 3)
		ptr->ptr_parse->unumber = va_arg(ptr->args, unsigned long long int);
	else if (ptr->ptr_parse->flag_size == 4)
		ptr->ptr_parse->unumber = va_arg(ptr->args, unsigned long int);
	else if (ptr->ptr_parse->flag_size == 5)
		ptr->ptr_parse->unumber = (unsigned char)va_arg(ptr->args, unsigned int);
	else if (ptr->ptr_parse->flag_size == 6)
		ptr->ptr_parse->unumber = (unsigned short int)va_arg(ptr->args, unsigned int);
	else
		ptr->ptr_parse->unumber = va_arg(ptr->args, unsigned int);
	makebase(ptr);
	ptr->tmp = ptr->ptr_parse->tmp;
	ft_makedot_oxu(ptr);
}

void	preparetosize(list *ptr)
{
	if (ptr->ptr_parse->flag_size == 1)
		ptr->ptr_parse->number = va_arg(ptr->args, intmax_t);
	else if (ptr->ptr_parse->flag_size == 2)
		ptr->ptr_parse->number = va_arg(ptr->args, size_t);
	else if (ptr->ptr_parse->flag_size == 3)
		ptr->ptr_parse->number = va_arg(ptr->args, long long int);
	else if (ptr->ptr_parse->flag_size == 4)
		ptr->ptr_parse->number = va_arg(ptr->args, long int);
	else if (ptr->ptr_parse->flag_size == 5)
		ptr->ptr_parse->number = (char)va_arg(ptr->args, int);
	else if (ptr->ptr_parse->flag_size == 6)
		ptr->ptr_parse->number = (short int)va_arg(ptr->args, int);
	else
		ptr->ptr_parse->number = va_arg(ptr->args, int);
	makebase(ptr);
	ptr->tmp = ptr->ptr_parse->tmp;
	ft_makedot(ptr);
}
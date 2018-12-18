#include "ft_printf.h"

void	ft_copy(list *ptr)
{
	while (ptr->tmp && *ptr->tmp && *ptr->tmp != '\0')
	{
		if (ptr->count == 1000)
		{
			ft_putstr(ptr->buffer);
			ptr->res += 1000;
			ft_bzero(ptr->buffer, 1000);
			ptr->count = 0;
		}
		ptr->buffer[ptr->count++] = *ptr->tmp;
		ptr->tmp++;
	}
}

int	ft_test2(list *ptr)
{
	while (*ptr->form != 'd' && *ptr->form != 'i' && *ptr->form != 'o' && *ptr->form != 'u' && *ptr->form != 'x'
			&& *ptr->form != 'X' && *ptr->form != 'p' && *ptr->form != 'c' && *ptr->form != 's' && *ptr->form != 'f' && *ptr->form != '\0')
	{
		
		if (!ft_strchr("#-+ jzhlL*.012,3456789", *ptr->form))
			break ;
		if (!*ptr->form){
			write(1, "Error", 1);
			return (1);
		}
		ptr->form++;
		if (*ptr->form && ft_strchr("diouxXpcsf", *ptr->form))
			return (2);
	}
	if (*ptr->form && !ft_strchr("diouxXpcsf", *ptr->form))
			ptr->buffer[ptr->count++] = *ptr->form;
	if (*ptr->form == '\0')
		return (0);
	return (2);
}

void	ft_search(list *ptr)
{
	int tmp;
	ptr->form_start = ptr->form;
	if ((tmp = ft_test2(ptr)) == 1)
		return ;
	else if (tmp == 2 && *ptr->form != '\0')
		ft_parse(ptr);
}

int ft_printf(const char *format, ... )
{
	list 	ptr[1];
	long long	i;

	i = ft_strlen(format);
	ft_bzero(ptr, sizeof(list));
	va_start(ptr->args, format);
	ptr->form = format;
	ptr->form_orig = format;
	while (*ptr->form != '\0' && *ptr->form && i--)
	{
		if (!ft_strchr(format, '%'))
		{
			ptr->res = ft_strlen(format);
			ft_putstr(format);
			return (ptr->res);
		}
		if (*ptr->form == '%')
		{
			ptr->form++;
			ft_search(ptr);
		}
		else if (i > 0)
			ptr->buffer[ptr->count++] = *ptr->form;
		if (ptr->count == 1000)
		{
			ft_putstr(ptr->buffer);
			ptr->count = 0;
		}
		ptr->form++;
	}
	ft_putstr(ptr->buffer);
	ptr->res += ft_strlen(ptr->buffer);
	va_end(ptr->args);
	return (ptr->res);
}



int	main(void)
{
	// int a = 2;
	// int b = 4;

	// argv = NULL;
	// argc = 0;
	// char *str;


	// char temp[] = "1111222123";
	// ft_printf("fefefef%%\n", 24);
	// ft_printf("\n\nfefefef%d\n\n\n", 24, 42);
	// ft_printf("%42.23L+- #f%42.23L+- #c%42.23L+- #s%42.23L+- #p%42.23L+- #d%42.23L+- #i%42.23L+- #o%42.23L+- #u%42.23L+- #x%42.23L+0- #0000000X%042.23L+- #X\n", 9223372036854775807);
	// printf("%10.2s is a string\n", "this");


	ft_printf("%f", 3.123);

	
	// system("leaks a.out");
	return (0);
}
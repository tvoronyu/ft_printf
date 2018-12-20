#include "ft_printf.h"

void	ft_copy(list *ptr)
{
	// ft_memcpy()
	while (ptr->tmp && *ptr->tmp && *ptr->tmp != '\0')
	{
		if (ptr->count == 1000)
		{
			write(1, ptr->buffer, ft_strlen(ptr->buffer));
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
		// if (!*ptr->form)
		// {
		// 	write(1, "Error", 1);
		// 	return (1);
		// }
		
		if (*ptr->form && ft_strchr("diouxXpcsf%", *ptr->form))
			return (2);
		ptr->form++;
	}
	// if (*ptr->form && !ft_strchr("diouxXpcsf", *ptr->form))
	// 		ptr->buffer[ptr->count++] = *ptr->form;
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
			write(1, format, ft_strlen(format));
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
			write(1, ptr->buffer, ft_strlen(ptr->buffer));
			ptr->count = 0;
		}
		ptr->form++;
	}
	write(1, ptr->buffer, ft_strlen(ptr->buffer));
	ptr->res += ft_strlen(ptr->buffer);
	va_end(ptr->args);
	return (ptr->res);
}



int	main(void)
{

	ft_printf("@moulitest: %c", 0);
	printf("@moulitest: %c", 0);
	// printf("tes%-10%%dtet", 23);


	
	// system("leaks a.out");
	return (0);
}
#include "ft_printf.h"


void	ft_makeproc(list *ptr)
{
	char		*tmp;

	if (ptr->ptr_parse->flag_width > 1)
	{
		tmp = ft_strnew(ptr->ptr_parse->flag_width - 1);
		if (ptr->ptr_parse->flag_zero && !ptr->ptr_parse->flag_minus)
		{
			ft_memset(tmp, '0', ptr->ptr_parse->flag_width - 1);
			ptr->tmp = ft_strjoin(tmp, "%");
		}
		else if (ptr->ptr_parse->flag_minus)
		{
			ft_memset(tmp, ' ', ptr->ptr_parse->flag_width - 1);
			ptr->tmp = ft_strjoin("%", tmp);
		}
		else
		{
			ft_memset(tmp, ' ', ptr->ptr_parse->flag_width - 1);
			ptr->tmp = ft_strjoin(tmp, "%");
		}
	}
	else if (ptr->ptr_parse->flag_width == 1 || !ptr->ptr_parse->flag_width)
		ptr->tmp = ft_strdup("%");
}

void	ft_makediff(list *ptr)
{

	ft_putendl(ptr->form);
	
}

void	ft_makewidth_str(list *ptr)
{

	long long	i;
	char		*tmp;
	char		*tmp_2;

	if ((i = ptr->ptr_parse->flag_width - ft_strlen(ptr->tmp)) > 0)
	{
		tmp = ft_strnew(i);
		if (ptr->ptr_parse->flag_zero && ptr->ptr_parse->flag_dot == 0 && !ptr->ptr_parse->flag_minus)
			ft_memset(tmp, '0', i);
		else
			ft_memset(tmp, ' ', i);
		if (ptr->ptr_parse->flag_minus)
			tmp_2 = ft_strjoin(ptr->tmp, tmp);
		else
			tmp_2 = ft_strjoin(tmp, ptr->tmp);
		free(tmp);
		ptr->tmp = ft_strdup(tmp_2);
	}
}

void	ft_makestr_dot(list *ptr)
{
	long long	i;
	char		*tmp;
	char		*tmp_2;

	i = 0;
	if (ptr->ptr_parse->flag_dot > 0)
	{
		if ((i = ptr->ptr_parse->flag_dot - ft_strlen(ptr->tmp)) <= 0)
		{
			tmp = ft_strnew(ptr->ptr_parse->flag_dot);
			tmp_2 = ft_strncpy(tmp, ptr->tmp, ptr->ptr_parse->flag_dot);
			free(tmp);
			ptr->tmp = ft_strdup(tmp_2);
		}
	}
	ft_makewidth_str(ptr);
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
	double f;
	long double ff;
	char *tmp;
	char str[1];

		if (*ptr->form == 'd' || *ptr->form == 'i')
			preparetosize(ptr);
			// res += ft_makeprintbl(preparetosize(full[2][0], ar, t), full, t);
		else if (*ptr->form == 'o' || *ptr->form == 'u' || *ptr->form == 'x' || *ptr->form == 'X')
			upreparetosize(ptr);
		// 	ft_putchar('o');
		// 	// res += ft_makeprintbl(upreparetosize(full[2][0], ar, t), full, t);
		else if (*ptr->form == 'c')
			{
				ptr->tmp = ft_strnew(1);
				ptr->tmp[0] = (va_arg(ptr->args, int));
				str[0] = 0;
				// write(1, str, 1);
			}
		// 	// res += ft_makewprintbl(ft_makewchar(va_arg(ar, wchar_t)), full, t);
		// else if (*ptr->form == 'p')
		// 	ft_putchar('p');
		// 	// res += ft_makeptr(printmemory(ar), full, t);
		else if (*ptr->form == 's')
			ft_makestr(ptr);
		else if (*ptr->form == 'f')
			{
				if (ptr->ptr_parse->flag_size == 7)
				{
					ff = va_arg(ptr->args, double);
					ptr->tmp = ft_ftoa(ff, ptr);
					// write(1, "fe", 2);
				}
				else
				{
					f = va_arg(ptr->args, double);
					ptr->tmp = ft_ftoa(f, ptr);
					// write(1, "fe", 2);
				}
			}
		else if (*ptr->form == '%')
			ft_makeproc(ptr);
		else
			ft_makediff(ptr);
	// }
	// return (res);
}
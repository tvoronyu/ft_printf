#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"
# include <wchar.h>

typedef	struct	list_parse
{
	char		flag_plus;
	char		flag_minus;
	char		flag_zero;
	char		flag_mult;
	char		flag_hash;
	char		flag_space;
	int			flag_dot;
	int			flag_width;
	int			flag_size;
	intmax_t	number;
	uintmax_t	unumber;
	char		*tmp;

}				list_parse;

typedef	struct	list
{
	list_parse	*ptr_parse;
	char		buffer[1000];
	int			count;
	char const	*form;
	char const	*form_start;
	char const	*form_orig;
	long long	counter;
	char		*str_format;
	char		*str;
	va_list		args;
	long long	res;
	char		*tmp;
}				list;

int		ft_printf(const char *format, ... );
int		ft_atoi_base(const char *str, int str_base);
char	*ft_itoa_base(int n, int base);
char	*ft_lowercase(char *str);
char	*ft_uppercase(char *str);
void	ft_parse(list *ptr);
void	ft_copy(list *ptr);
void	ft_find_flag(list *ptr);
void	ft_modificator(list *ptr);
void	ft_find_size(list *ptr);
void	ft_find_type(list *ptr);
void	preparetosize(list *ptr);
void	upreparetosize(list *ptr);
char	*ft_itoamax(intmax_t n);
void	ft_makedot(list *ptr);

#endif
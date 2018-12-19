#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"
# include <wchar.h>
# define BUFF_SIZE 4096

typedef	struct	list_parse
{
	char		flag_plus;
	char		flag_minus;
	char		flag_zero;
	char		flag_mult;
	char		flag_hash;
	char		flag_space;
	intmax_t	flag_dot;
	size_t		flag_width;
	size_t		flag_size;
	intmax_t	number;
	uintmax_t	unumber;
	char		*tmp;
	int    len;
	int	len_full;
	int  		precision_field;
	char		*s;
	int 		i;
	int 		dot;
	char		str_full[BUFF_SIZE];

}				list_parse;

typedef	struct	list
{
	list_parse	*ptr_parse;
	char		buffer[1000];
	size_t		count;
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
void	ft_makewidth(list *ptr);
void	ft_makedot_oxu(list *ptr);
void	ft_makewidth_oxu(list *ptr);
char			*ft_float(char *str_ptr, list *ptr);
unsigned long	ft_mantisa(char *str, int *exponent);
int				ft_exponent(char *str);
char	*ft_float_add_exponent(char *str, list *ptr, int count, char type);
int		ft_float_dot(list *ptr);
char	*ft_float_binary(unsigned long *ptr);
char	*ft_float_add_minus(char *str, list *ptr);
int		ft_float_minus(long double *n);
char	*ft_float_check(char *str, list *ptr);
char	*ft_float_infinite_zero(char *str, list *ptr);
char	*ft_my_strdup(const char *s, list *ptr);
char	*ft_round_float(char *str, list *ptr);
char	*ft_round_float_2(char *str, list *ptr);
char	*ft_ftoa(double n, list *ptr);
char	*ft_ftoa_precision(char *str, list *ptr);
char	*ft_ftoa_precision2(char *new, char *str, list *ptr, int af);
void	ft_expand(char **form, list *ptr);
void	ft_my_strcat(list *ptr, char *s1, int len);
char	*ft_str_join_char_free(char *s1, int len, char c);
char	*ft_str_join_free(char *s1, char *s2, int len1, int len2);
char	*ft_str_div_two(char *s, int *len);
int		ft_dot(int *dot, char s_i, char *s);
char	*ft_pow_two(int pow, list *ptr);
char	*ft_str_mul_two(char *s, int *len);
char	*ft_cut(char *str, int *len);
int			ft_nochar_index(char *str, char c1, char c2);
int			ft_char_index(char *str, char c);
int			ft_numcount_base_unsign(unsigned long n, int base);
int			ft_numcount_base_sign(long n, int base);
int		ft_minus_2(int *pow);
int		ft_len_chr_str(const char *s, int start, char *sub);
int		ft_lenchr(const char *s, int *start, char c);
int		ft_str_chr_all(const char *str, char c);

#endif
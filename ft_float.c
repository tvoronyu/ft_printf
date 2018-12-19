/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:15:42 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/20 15:15:43 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_u(char const *str_base, int *len,
unsigned long n, int base)
{
	char			*str;
	int				i;

	*len = ft_numcount_base_unsign(n, base);
	str = ft_strnew(*len);
	i = *len;
	while (i--)
	{
		str[i] = str_base[n % base];
		n = n / base;
	}
	return (str);
}

int				ft_exponent(char *str)
{
	int i;
	int exponent;
	int two;

	i = -1;
	exponent = 0;
	two = 1024;
	while (++i < 11)
	{
		if (str[1 + i] == '1')
			exponent += two;
		two /= 2;
	}
	exponent -= 1023;
	return (exponent);
}

unsigned long	ft_mantisa(char *str, int *exponent)
{
	int				len;
	unsigned long	mantisa;
	unsigned long	two;

	len = 53;
	mantisa = 1;
	while (--len)
	{
		if (str[len + 11] == '1')
		{
			*exponent = *exponent - len;
			two = 1;
			mantisa = two;
			while (--len)
			{
				two *= 2;
				if (str[len + 11] == '1')
					mantisa += two;
			}
			mantisa += two * 2;
			break ;
		}
	}
	return (mantisa);
}

char			*ft_float(char *str_ptr, list *ptr)
{
	char			*str;
	unsigned long	mantisa;
	int				exponent;

	str_ptr = ft_float_infinite_zero(str_ptr, ptr);
	if (ptr->ptr_parse->len)
		return (str_ptr);
	else
	{
		exponent = ft_exponent(str_ptr);
		mantisa = ft_mantisa(str_ptr, &exponent);
		str = ft_itoa_base_u("0123456789", &ptr->ptr_parse->len, mantisa, 10);
		if (exponent > 0)
			while (exponent--)
				str = ft_str_mul_two(str, &ptr->ptr_parse->len);
		else if (exponent < 0)
			while (exponent++)
				str = ft_str_div_two(str, &ptr->ptr_parse->len);
	}
	return (str);
}

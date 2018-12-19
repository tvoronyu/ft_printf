/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:34:40 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/06/14 13:34:42 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ftoa_precision2(char *new, char *str, list *ptr, int af)
{
	if (ptr->ptr_parse->dot)
		new[ptr->ptr_parse->i++] = '.';
	while (af-- > 1 && ptr->ptr_parse->precision_field > 0)
	{
		--ptr->ptr_parse->precision_field;
		new[ptr->ptr_parse->i] = str[ptr->ptr_parse->i];
		++ptr->ptr_parse->i;
	}
	ptr->ptr_parse->len = ptr->ptr_parse->i;
	if (af > 0)
		if (str[ptr->ptr_parse->i + 1 - ptr->ptr_parse->dot] >= '5')
			new = ft_round_float(new, ptr);
	ptr->ptr_parse->i = ptr->ptr_parse->len;
	while (ptr->ptr_parse->precision_field-- > 0)
		new[ptr->ptr_parse->i++] = '0';
	ptr->ptr_parse->len = ptr->ptr_parse->i;
	ft_strdel(&str);
	return (new);
}

char	*ft_ftoa_precision(char *str, list *ptr)
{
	int		after_dot_len;
	int		before_dot_len;
	char	*new;

	ptr->ptr_parse->dot = ft_float_dot(ptr);
	ptr->ptr_parse->i = -1;
	while (++ptr->ptr_parse->i < ptr->ptr_parse->len)
		if (str[ptr->ptr_parse->i] == '.')
			break ;
	before_dot_len = ptr->ptr_parse->i;
	after_dot_len = ptr->ptr_parse->len - before_dot_len;
	new = ft_strnew(before_dot_len + ptr->ptr_parse->precision_field + ptr->ptr_parse->dot);
	ptr->ptr_parse->i = -1;
	while (++ptr->ptr_parse->i < before_dot_len)
		new[ptr->ptr_parse->i] = str[ptr->ptr_parse->i];
	new = ft_ftoa_precision2(new, str, ptr, after_dot_len);
	return (new);
}

char	*ft_ftoa(double n, list *ptr)
{
	char	*str_ptr;
	char	*str;

	ptr->ptr_parse->precision_field = -1;
	str_ptr = ft_float_binary((unsigned long*)(&n));
	str_ptr = ft_float_check(str_ptr, ptr);
	if (ptr->ptr_parse->len)
		return (str_ptr);
	str = ft_float(str_ptr, ptr);
	str = ft_ftoa_precision(str, ptr);
	if (str_ptr[0] == '1')
		str = ft_float_add_minus(str, ptr);
	if (ptr->ptr_parse->flag_hash)
		if (ft_char_index(str, '.') == ptr->ptr_parse->len)
			str = ft_str_join_char_free(str, ptr->ptr_parse->len++, '.');
	ft_strdel(&str_ptr);
	return (str);
}

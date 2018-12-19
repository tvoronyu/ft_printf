/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:55:00 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/07/03 10:55:01 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_my_strdup(const char *s, list *ptr)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	ptr->ptr_parse->len = ft_strlen(s);
	str = ft_strnew(ptr->ptr_parse->len);
	i = -1;
	while (++i < ptr->ptr_parse->len)
		str[i] = s[i];
	return (str);
}

char	*ft_float_infinite_zero(char *str, list *ptr)
{
	ptr->ptr_parse->s = "0000000000000000000000000000000000000000000000000000000001000000";
	if (ft_strcmp(str, ptr->ptr_parse->s) == 0)
		return (ft_my_strdup("0.0", ptr));
	ptr->ptr_parse->s = "0000000000000000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, ptr->ptr_parse->s) == 0)
		return (ft_my_strdup("0", ptr));
	ptr->ptr_parse->s = "1000000000000000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, ptr->ptr_parse->s) == 0)
		return (ft_my_strdup("0", ptr));
	return (str);
}

char	*ft_float_check(char *str, list *ptr)
{
	ptr->ptr_parse->s = "1111111111110000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, ptr->ptr_parse->s) == 0)
	{
		ft_strdel(&str);
		if (*ptr->form >= 97)
			return (ft_my_strdup("-inf", ptr));
		return (ft_my_strdup("-INF", ptr));
	}
	ptr->ptr_parse->s = "0111111111110000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, ptr->ptr_parse->s) == 0)
	{
		ft_strdel(&str);
		if (*ptr->form >= 97)
			return (ft_my_strdup("inf", ptr));
		return (ft_my_strdup("INF", ptr));
	}
	ptr->ptr_parse->s = "0111111111111000000000000000000000000000000000000000000000000000";
	if (ft_strcmp(str, ptr->ptr_parse->s) == 0)
	{
		ft_strdel(&str);
		if (*ptr->form >= 97)
			return (ft_my_strdup("nan", ptr));
		return (ft_my_strdup("NAN", ptr));
	}
	return (str);
}

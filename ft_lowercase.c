/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:41:10 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/11/10 15:41:13 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Функція приймає на вхід строку і
усі заголовні букви робить прописними виділивши
память і переписуючи туди кожен символ
і повертає новустворену строку викликаючій
функції Память після неї треба чистити. */

#include "ft_printf.h"

char	*ft_lowercase(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i] && str[i] != '\0')
	{
		tmp[i] = ft_tolower(str[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

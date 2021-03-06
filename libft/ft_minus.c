/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:31:11 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/04/05 09:26:05 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_minus(int *n, int *neg, int *len)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
		*len += 1;
	}
}

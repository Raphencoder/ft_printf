/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:08:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 19:42:37 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoap(long long nb)
{
	long long	clone;
	int			i;
	char		*res;

	i = 0;
	clone = nb;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	res = (char*)ft_memalloc(sizeof(char) * i + 2);
	while (clone >= 10)
	{
		res[i] = (clone % 10) + 48;
		clone = clone / 10;
		i--;
	}
	res[i] = clone + 48;
	return (res);
}

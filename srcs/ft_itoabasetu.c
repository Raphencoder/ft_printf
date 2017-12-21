/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:37:54 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/21 18:42:46 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char    *ft_itoabasetu(char *base, long long nb)
{
	int b;
	char *res;
	char *tmp;
	int	sign;

	sign = 0;
	if (nb < 0)
	{
		sign = -1;
		nb = -nb;
	}	
	res = ft_strnew(2);
	b = ft_strlen(base);
	*res = base[nb % b];
	tmp = res;
	nb = nb / b;
	if (nb != 0)
	{
		res = ft_strjoin(ft_itoabase(base, nb), res);
		free (tmp);
	}
	if (sign == -1)
		res = ft_strjoin("-", res);
	return (res);
}

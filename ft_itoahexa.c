/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/13 17:34:05 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int			ft_handlesign(int value, int *j)
{
	static int flag;

	if (value < 0 && flag == 0)
	{
		value = -value;
		flag++;
		*j = *j + 1;
	}
	if (flag)
		return (1);
	return (0);
}

int			ft_string(int d)
{
	char	*str;

	str = "ABCDEF";
	d = (int)str[d - 10];
	return (d);
}

char		*ft_fillchr(char *chr, int *res, int i, int j)
{
	int value;

	value = 0;
	while (i >= 0)
	{
		if (ft_handlesign(value, &j))
			chr[j - 1] = '-';
		if (ft_intisdigit(res[i]))
			chr[j] = (res[i]) + 48;
		else
			chr[j] = (res[i]);
		i--;
		j++;
	}
	return (chr);
}

char		*ft_itoahexa(int value)
{
	int		i;
	int		*res;
	char	*chr;
	int		j;

	j = 0;
	i = 0;
	res = (int*)malloc(sizeof(int) * 10);
	ft_handlesign(value, &j);
	while (value)
	{
		res[i] = value % 16;
		if (res[i] >= 10)
			res[i] = ft_string(res[i]);
		value = value / 16;
		i++;
	}
	chr = (char*)malloc(sizeof(char) * i);
	chr[i] = '\0';
	chr = ft_fillchr(chr, res, i - 1, j);
	return (chr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/14 21:05:21 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*ft_itoabase(char *base, uintmax_t nb)
{	
	int b;
	char *res;
	char *tmp;

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
	return (res);
}

char	*ft_choosebase(char *str)
{
	int i;
	char *tmp;

	i = 0;
	while (!ft_isspec(str[i]))
		i++;
	if (str[i] == 'o')
		return (ft_itoabase("01234567", 8));
	else if (str[i] == 'x' || str[i] == 'p')
	{
			if (str[i] == 'p')
				return (ft_strjoin("0x", ft_itoabase("0123456789abcdef", 16)));
		return (ft_itoabase("0123456789abcdef", 16));
	}
	else if (str[i] == 'X')
		return (ft_itoabase("0123456789ABCDEF", 16));
	else if (str[i] == 'u')
		return (ft_itoabase("0123456789", 10));
	else if (str[i] == 'b')
		return (ft_itoabase("01234567", 8));
	return (NULL);
}

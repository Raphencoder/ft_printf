/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:51:08 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/19 14:24:07 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len_int(intmax_t n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	else
		return (ft_len_int(n / 10) + 1);
}

static char		*ft_while_itoa(int len_int, char *str, intmax_t nbr)
{
	while (len_int >= 0)
	{
		str[len_int] = '0' + (nbr % 10);
		len_int--;
		nbr /= 10;
	}
	return (str);
}

char			*ft_itoac(intmax_t nbr)
{
	char	*str;
	int		len_int;
	int		m;

	m = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len_int = ft_len_int(nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		m = 1;
	}
	str = ft_strnew(len_int + m);
	if (str == NULL)
		return (NULL);
	str[len_int + 1] = '\0';
	if (m == 0)
		len_int--;
	str = ft_while_itoa(len_int, str, nbr);
	if (m == 1)
		str[0] = '-';
	return (str);
}

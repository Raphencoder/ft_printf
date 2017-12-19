/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:20:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/19 16:03:52 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_len_int(uintmax_t n)
{
	if (n < 10)
		return (1);
	else
		return (ft_len_int(n / 10) + 1);
}

static char     *ft_while_itoa(uintmax_t len_int, char *str, uintmax_t nbr)
{
	while (len_int >= 0)
	{
		str[len_int] = '0' + (nbr % 10);
		len_int--;
		nbr /= 10;
	}
	return (str);
}

char            *ft_itoast(size_t nbr)
{
	char    *str;
	uintmax_t    len_int;
	uintmax_t	nb;

	nb = ((uintmax_t)nbr);
//	ft_putnbr(nb);
	ft_putchar('\n');
	len_int = ft_len_int(nb);
	str = ft_strnew(len_int);
	if (str == NULL)
		return (NULL);
	str[len_int + 1] = '\0';
	str = ft_while_itoa(len_int, str, nb);
	ft_putendl(str);
	return (str);
}

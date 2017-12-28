/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/28 01:04:39 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

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

char	*ft_itoalld(long long int nb)
{	
	long long int clone;
	int	i;
	char *res;
	int	sign;

	sign = 0;
	i = 0;
	if (nb < 0)
	{
		i = 1;
		sign = 1;
		nb = -nb;
	}
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
	if (sign)
		res[0] = '-';
	return (res);
}

char    *ft_itoazd(size_t nb)
{
	size_t clone;
	int i;
	char *res;

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

char    *ft_itoajd(intmax_t nb)
{
	intmax_t clone;
	int i;
	char *res;

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

char    *ft_itoald(long int nb)
{
	long int clone;
	int i;
	char *res;
	int sign;

	sign = 0;
	i = 0;
	if (nb < 0)
	{
		i = 1;
		sign = 1;
		nb = -nb;
	}
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
	if (sign)
		res[0] = '-';
	return (res);
}

char    *ft_itoahd(short int nb)
{
	short int clone;
	int i;
	char *res;
	int sign;

	sign = 0;
	i = 0;
	if (nb < 0)
	{
		i = 1;
		sign = 1;
		nb = -nb;
	}
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
	if (sign)
		res[0] = '-';
	return (res);
}

char    *ft_itoad(int nb)
{
	int clone;
	int i;
	char *res;
	int sign;

	sign = 0;
	i = 0;
	if (nb < 0)
	{
		i = 1;
		sign = 1;
		nb = -nb;
	}
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
	if (sign)
		res[0] = '-';
	return (res);
}

char    *ft_itoau(unsigned long long nb)
{
	unsigned long long clone;
	int i;
	char *res;

	if ((int)nb < 0)
		nb = 4294967295;
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

char	*ft_choosebase(char *str, uintmax_t nb)
{
	int i;
	int	j;
	char *flag;
	
	i = 0;
	j = 0;
	flag = ft_strnew(3);
	while (!ft_isspec(str[i]))
		flag[j++] = str[i++];
		flag[j] = str[i];
	if (ft_strequ(flag, "hhd") || ft_strequ(flag, "hhi"))
		{
			if (nb / 10 == 0)
				return ((char*)(nb));
			else 
				return (ft_itoad(nb));
		}
	else if (ft_strequ(flag, "hd") || ft_strequ(flag, "hi"))
		return (ft_itoahd(nb));
	else if (ft_strequ(flag, "ld") || ft_strequ(flag, "li"))
		return (ft_itoald(nb));
	else if (ft_strequ(flag, "lld") || ft_strequ(flag, "lli"))
		return (ft_itoalld(nb));
	else if (ft_strequ(flag, "jd") || ft_strequ(flag, "ji"))
		return (ft_itoajd(nb));
	else if (ft_strequ(flag, "zd") || ft_strequ(flag, "zi"))
		return (ft_itoazd(nb));
	if (str[i] == 'o')
		return (ft_itoabase("01234567", nb));
	else if (str[i] == 'x' || str[i] == 'p')
	{
		if (str[i] == 'p')
			return (ft_strjoin("0x", ft_itoabase("0123456789abcdef", nb)));
		return (ft_itoabase("0123456789abcdef", nb));
	}
	else if (str[i] == 'X')
		return (ft_itoabase("0123456789ABCDEF", nb));
	else if (str[i] == 'u')
		return (ft_itoau(nb));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_itoad(nb));
	else if (str[i] == 'b')
		return (ft_itoabase("01234567", nb));
	return (NULL);
}

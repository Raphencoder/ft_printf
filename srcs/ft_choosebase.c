/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/21 11:22:00 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char	*ft_itoabasesi(char *base, short int nb)
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
	else if (str[i] == 'u' || str[i] == 'd')
	{
		if (ft_strequ(flag, "hh"))
			return (ft_itoabasesi("0123456789", nb));
		else	
			return (ft_itoabase("0123456789", nb));
	}
	else if (str[i] == 'b')
		return (ft_itoabase("01234567", nb));
	return (NULL);
}

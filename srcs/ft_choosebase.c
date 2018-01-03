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

char	*ft_itoabase(char *base, uintmax_t nb)
{
	int		b;
	char	*res;
	char	*tmp;

	res = ft_strnew(2);
	b = ft_strlen(base);
	*res = base[nb % b];
	tmp = res;
	nb = nb / b;
	if (nb != 0)
	{
		res = ft_strjoin(ft_itoabase(base, nb), res);
		free(tmp);
	}
	return (res);
}

char	*ft_itoau(uintmax_t nb)
{
	uintmax_t	clone;
	int			i;
	char		*res;

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

	i = 0;
	j = 0;
	j = ft_takespec(str);
	if (j == 'o')
		return (ft_itoabase("01234567", nb));
	else if (j == 'x' || j == 'p')
	{
		if (j == 'p')
			return (ft_strjoin("0x", ft_itoabase("0123456789abcdef", nb)));
		return (ft_itoabase("0123456789abcdef", nb));
	}
	else if (j == 'X')
		return (ft_itoabase("0123456789ABCDEF", nb));
	else if (j == 'u')
		return (ft_itoau(nb));
	else if (j == 'b')
		return (ft_itoabase("01234567", nb));
	return (NULL);
}

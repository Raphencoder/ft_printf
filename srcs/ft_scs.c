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

#include "ft_printf.h"

char	*ft_scs(int nb, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (nb <= 0)
		return (ft_strdup(""));
	str = (char*)ft_memalloc(sizeof(char) * nb + 1);
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreatspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:12:54 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/14 21:18:03 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_scs(int nb, char c)
{
	char *str;
	int	i;

	i = 0;
	if (nb == 0)
		return (NULL);
	str = (char*)ft_memalloc(sizeof(char) * nb + 1);
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takeflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:16:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/17 11:18:39 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_takeflag(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && !ft_isspec(str[i]))
		i++;
	if (str[i] == 'U' || str[i] == 'D' || str[i] == 'O')
		return (ft_strdup("l"));
	if (i == 0)
		return (NULL);
	res = ft_strndup(str, i);
	return (res);
}

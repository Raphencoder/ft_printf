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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grepspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:47:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/18 21:22:53 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function return a string that begin with the first length(hh, h, ..)
**	and ends with the last spec (d, i, ..). It allows to compare more easily in
**	the function ft_findspec.
**	This function take in parameter the content of the link.
*/

char 	*ft_grepspec(char *str)
{
	int		i;
	int		j;
	char	*clone;
	int		check;

	check = 0;
	i = 0;
	j = 0;
	if (str[0] != '%')
		return (NULL);
	i++;
	while ((!ft_isspec(str[i]) && str[i]))
		i++;
	if (ft_isspec(str[i]))
	{
		j = i;
		while (!ft_islength(str, i) && i > 0)
			i--;
		if (i == 0)
			return (ft_strcpy(ft_strnew(2), (const char*)j));
		while (ft_islength(str, i))
			i--;
		i++;
		return (ft_strsub(str, i, (j - i + 1)));
	}
	return (NULL);
}

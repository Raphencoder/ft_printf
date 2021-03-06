/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grepspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:47:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/02 14:20:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function return a string that begin with the first length(hh, h, ..)
**	and ends with the last spec (d, i, ..). It allows to compare more easily in
**	the function ft_findspec.
**	This function take in parameter the content of the link.
*/

char		*ft_grepspec(char *str)
{
	int		i;
	int		j;
	int		check;
	int		flag;

	flag = 0;
	check = 0;
	i = 1;
	j = 0;
	if (str[0] != '%')
		return (NULL);
	while (!ft_islength(str[i]) && str[i])
	{
		i++;
		flag = 1;
	}
	if (!str[i])
		return (ft_strsub(str, i - 1, 1));
	j = i;
	while ((ft_islength(str[i]) || ft_isspec(str[i])) && str[i])
	{
		i++;
		check++;
	}
	return (ft_strsub(str, j, check));
}

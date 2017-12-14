/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grepspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:47:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/14 20:56:47 by rkrief           ###   ########.fr       */
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
	i = 0;
	j = 0;

	while (!ft_islength(str, i))
			i++;
	i = j;
	while (ft_isspec(str[i]))
		i++;
	clone = ft_strsub(str, j, (i - j - 1));
	return (clone);
}

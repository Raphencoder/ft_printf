/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:08:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/02 14:12:01 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function check is the character 'c' is a specfier.
*/

int		ft_isspec(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (1);
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G')
		return (1);
	if (c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'p' || c == '%')
		return (1);
	if (c == 'S' || c == 'n' || c == 'b')
		return (1);
	if (c == 'D' || c == 'O' || c == 'U')
	{
		c = ft_tolower(c);
		return (1);
	}
	return (0);
}

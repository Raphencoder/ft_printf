/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islength.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:17:51 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/19 20:48:27 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function check if the specific character at the 'i' position is a
**	'length' type.
*/

int		ft_islength(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' 
			|| c == 't' || c == 'L')
		return (1);
	return (0);
}

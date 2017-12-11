/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:24:08 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 19:20:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function will spot if the character passed in parameter is a 'flag' 
*/

int		ft_isflag(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

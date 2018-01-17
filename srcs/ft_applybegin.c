/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:40:39 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/17 13:14:08 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_applybegin(t_case *block, char *s, int *hey, int *sign)
{
	if (hey)
		*hey = 1;
	if (block->flag.sharp && block->flag.zero && block->flag.width &&
			block->flag.spec != 'o')
		block->flag.width -= 2;
	if ((block->flag.spec == 'd' || block->flag.spec == 'i'))
	{
		if (ft_strchr(s, '-'))
			*sign = 1;
	}
	if (block->flag.dot == -1 && ft_strequ(s, "0"))
	{
		if (block->flag.spec == 'o' && block->flag.sharp)
			return (s);
		s = ft_strdup("");
	}
	return (s);
}

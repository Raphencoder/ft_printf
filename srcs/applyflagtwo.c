/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:34:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 19:30:22 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ifspeco(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] <= 32)
		i++;
	if (s[i] != '0')
		s = ft_strjoin("0", s);
	return (s);
}

char		*applyflagtwo(t_case *block, char *s, int sign)
{
	if ((block->flag.plus) && block->flag.width && !sign && s[0] != '-')
		block->flag.width--;
	if (block->flag.spec != 's' && block->flag.spec != 'c')
	{
		if (block->flag.width && block->flag.dot)
		{
			if (block->flag.dot > block->flag.width)
				block->flag.less = 0;
		}
	}
	if (block->flag.sharp && (block->flag.spec == 'X' ||
block->flag.spec == 'x' || block->flag.spec == 'o') && block->flag.dot != -1 &&
			(!ft_strequ("0", s)) && !block->flag.zero)
	{
		if (block->flag.spec == 'X')
			s = ft_strjoin("0X", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0x", s);
		else if (block->flag.spec == 'o')
			s = ifspeco(s);
	}
	return (s);
}

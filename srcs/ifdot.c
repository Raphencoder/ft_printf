/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/10 15:00:55 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ifdottwo(t_case *block, char *s, int sign)
{
	if (sign)
		sign = 1;
	if (block->flag.width > block->flag.dot)
	{
		if (block->flag.sharp)
			s = ft_strjoin(ft_scs((block->flag.width - (((int)ft_strlen(s)) + 2)),
' '), s);
		else
			s = ft_strjoin(ft_scs((block->flag.width - ((int)ft_strlen(s) + block->flag.plus)),
' '), s);
	}
	return (s);
}

char		*ifdot(t_case *block, char *s, int sign, int *hey)
{
	if (block->flag.spec == 's' || block->flag.spec == 'c')
	{
		if (block->flag.dot < (int)ft_strlen(s))
			s = ft_strndup(s, block->flag.dot);
	}
	else
	{
		if (block->flag.neg && block->flag.dot > (int)ft_strlen(s) - 1)
			s = ft_strjoin(ft_scs((block->flag.dot - ((int)ft_strlen(s) - 1)),
'0'), s);
		else if (block->flag.dot > (int)ft_strlen(s))
			s = ft_strjoin(ft_scs((block->flag.dot - ((int)ft_strlen(s))),
'0'), s);
	}
	if (block->flag.zero && block->flag.width)
	{
		*hey = 1;
		s = ifdottwo(block, s, sign);
	}
	return (s);
}

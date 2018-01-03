/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/28 01:04:39 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ifdottwo(t_case *block, char *s, int sign)
{
	if (block->flag.width > block->flag.dot)
	{
		if (sign)
			s = ft_strjoin(ft_scs((block->flag.width - ((int)ft_strlen(s))),
' '), s);
		else
			s = ft_strjoin(ft_scs((block->flag.width - (int)ft_strlen(s)),
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
		if (sign && block->flag.dot > (int)ft_strlen(s) - 1)
			s = ft_strjoin(ft_scs((block->flag.dot - ((int)ft_strlen(s) - 1)),
'0'), s);
		else if (block->flag.dot > (int)ft_strlen(s))
			s = ft_strjoin(ft_scs((block->flag.dot - (int)ft_strlen(s)),
'0'), s);
	}
	if (block->flag.zero && block->flag.width)
	{
		*hey = 1;
		s = ifdottwo(block, s, sign);
	}
	return (s);
}

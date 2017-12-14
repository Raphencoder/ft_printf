/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:23:52 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/14 21:12:55 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char		*ft_applyflag(t_case *block, va_list arglst)
{
	char *s;

	s = block->content;
	if (block->flag.plus)
		s =ft_strjoin("+", s);
	if (block->flag.less)
		s =ft_strjoin(ft_scs(block->flag.width - ft_strlen(s), ' '), s);
	if (block->flag.zero && !block->flag.less)
		s = ft_strjoin(ft_scs(block->flag.width - ft_strlen(s), '0'), s);
	if (block->flag.space)
	{
		if (block->flag.plus)
			 return (s);
		if (ft_issigned(s))
			return (s);
		s = ft_strjoin(" ", s);
	}
	return (s);
}

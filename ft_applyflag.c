/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:23:52 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/18 19:48:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char		*ft_applyflag(t_case *block, char *s)
{
	int 	sign;
	char	*tmp;

	sign = 0;
	if (s[0] == '-')
	{
		tmp = s;
		s = ft_strdup(s + 1);
		free(tmp);
		block->flag.plus = 0;
		sign = 1;
	}
	if (block->flag.less)
		s = ft_strjoin(s, ft_scs(block->flag.width - ft_strlen(s), ' '));
	if (block->flag.space)
	{
		if (block->flag.plus)
			 return (s);
		if (ft_issigned(s))
			return (s);
		if (block->flag.spec == 's')
			block->flag.spec = 's';
		else
			s = ft_strjoin(" ", s);
	}
	if (block->flag.zero && !block->flag.less)
	{
		if (block->flag.plus || sign)
			s = ft_strjoin(ft_scs(block->flag.width - ft_strlen(s) - 1, '0'), s);
		else
			s = ft_strjoin(ft_scs(block->flag.width - ft_strlen(s), '0'), s);

	}
	if (block->flag.plus || sign)
	{
		if (sign)
			s = ft_strjoin("-", s);
		else
			s = ft_strjoin("+", s);
	}	
	return (s);
}

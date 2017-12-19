/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:23:52 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/20 00:52:06 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char		*ft_applyflag(t_case *block, char *s)
{
	int 	sign;
	char	*tmp;

	ft_putendl(s);
	ft_putnbr(block->flag.spec);
	sign = 0;
	if (s != NULL && s[0] == '-')
	{
		tmp = s;
		s = ft_strdup(s + 1);
		free(tmp);
		block->flag.plus = 0;
		sign = 1;
	}
	if (block->flag.less && !ft_ischar(block->flag.spec))
		s = ft_strjoin(s, ft_scs(block->flag.width - ft_strlen(s), ' '));
	if (block->flag.space && !ft_ischar(block->flag.spec))
	{
		if (block->flag.plus && !ft_ischar(block->flag.spec))
			 return (s);
		if (ft_issigned(s))
			return (s);
		if (block->flag.spec == 's')
			block->flag.spec = 's';
		else if (!block->flag.width)
			s = ft_strjoin(" ", s);
	}
	ft_putendl(s);
	if (block->flag.zero && !block->flag.less && !ft_ischar(block->flag.spec))
	{
		if (block->flag.plus || sign)
			s = ft_strjoin(ft_scs(block->flag.width - ft_strlen(s) - 1, '0'), s);
		else
			s = ft_strjoin(ft_scs(block->flag.width - ft_strlen(s), '0'), s);

	}
	ft_putendl(s);
	if (block->flag.sharp && (block->flag.spec == 'o') && *block->content != '0')
		s = ft_strjoin("0", s);
	else if  (block->flag.sharp && (block->flag.spec == 'x') && *block->content != '0')
		s = ft_strjoin("0x", s);
	else if  (block->flag.sharp && (block->flag.spec == 'X' && *block->content != '0'))
		s = ft_strjoin("0X", s);
//	ft_putendl(s);
	//ft_putnbr(block->flag.width);
//	ft_putchar('\n');
//	ft_putnbr(ft_strlen(s));
	if (((block->flag.plus || sign) && !ft_ischar(block->flag.spec)) && !block->flag.sharp)
	{
		if (sign)
			s = ft_strjoin("-", s);
		else
			s = ft_strjoin("+", s);
	}
	else if (block->flag.width)
		s = ft_strjoin(ft_scs(block->flag.width - ft_strlen(s), ' '), s);
//	ft_putendl(s);
	return (s);
}

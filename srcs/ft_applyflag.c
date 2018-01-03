/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:40:39 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/28 02:11:50 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*applyflagtwo(t_case *block, char *s, int sign)
{
	if ((block->flag.plus) && block->flag.width && !sign)
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
ft_strcmp("0", s) && !block->flag.zero)
	{
		if (block->flag.spec == 'X')
			s = ft_strjoin("0X", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0x", s);
		else if (block->flag.spec == 'o')
			s = ft_strjoin("0", s);
	}
	return (s);
}

char		*ft_applyflagthree(t_case *block, char *s)
{
	if (block->flag.width && !block->flag.zero)
	{
		if (block->flag.less)
			s = ft_strjoin(s, ft_scs(block->flag.width - (int)ft_strlen(s),
' '));
		else
			s = ft_strjoin(ft_scs(block->flag.width - (int)ft_strlen(s),
' '), s);
	}
	if (block->flag.sharp && (block->flag.spec == 'X' || block->flag.spec == 'x'
	|| block->flag.spec == 'o') && block->flag.dot != -1 &&
ft_strcmp("0", s) && block->flag.zero)
	{
		if (block->flag.spec == 'X')
			s = ft_strjoin("0X", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0x", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0", s);
	}
	return (s);
}

char		*ft_applyflagbegin(t_case *block, char *s, int *hey, int *sign)
{
	*hey = 0;
	*sign = 0;
	if (block->flag.sharp && block->flag.zero && block->flag.width)
		block->flag.width -= 2;
	if (!block->flag.less && (block->flag.spec == 'd' ||
block->flag.spec == 'i'))
	{
		if (ft_strchr(s, '-'))
			*sign = 1;
	}
	if (block->flag.dot == -1 && !ft_strcmp(s, "0") && !block->flag.sharp)
		s = ft_strdup("");
	else if (block->flag.dot == -1 && ft_strequ(s, "0"))
	{
		if (block->flag.sharp && block->flag.spec != 'o')
			s = ft_strdup("");
	}
	return (s);
}

char		*ft_applyflag(t_case *block, char *s)
{
	int sign;
	int hey;

	s = ft_applyflagbegin(block, s, &hey, &sign);
	s = applyflagtwo(block, s, sign);
	if (block->flag.dot)
		s = ifdot(block, s, sign, &hey);
	if (block->flag.zero && block->flag.spec != 's' && block->flag.spec != 'c'
	&& block->flag.dot == 0)
		s = ft_strjoin(ft_scs(block->flag.width - (int)ft_strlen(s), '0'), s);
	if (block->flag.less && !block->flag.zero)
		s = ft_strjoin(s, ft_scs(block->flag.width - (int)ft_strlen(s), ' '));
	s = ft_applyflagthree(block, s);
	if (block->flag.space && (!block->flag.width && !block->flag.less) &&
	!block->flag.plus && !sign)
		s = ft_strjoin(" ", s);
	if (sign && (block->flag.zero || block->flag.dot))
		s = ft_deletechar(s, '-');
	if (sign && (block->flag.zero || block->flag.dot))
		s = ft_putspace(block, s);
	if (block->flag.plus && !sign)
		s = ft_putspacetwo(block, s);
	return (s);
}

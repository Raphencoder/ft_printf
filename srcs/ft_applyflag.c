/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:40:39 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 14:59:17 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char		*applyflagtwo(t_case *block, char *s, int sign)
{
	int i;
	i = 0;
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
			(ft_strcmp("0", s) != 0) && !block->flag.zero)
	{
		if (block->flag.spec == 'X')
			s = ft_strjoin("0X", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0x", s);
		else if (block->flag.spec == 'o')
		{
			while (s[i] && s[i] <= 32)
				i++;
			if (s[i] != '0')
				s = ft_strjoin("0", s);
		}
	}
	return (s);
}

char		*ft_applyflagthree(t_case *block, char *s)
{
	int i;
	char *tmp;
	if (block->flag.width && !block->flag.zero)
	{
		if (block->flag.less)
			s = ft_strjoin(s, ft_scs((block->flag.width) - (((int)ft_strlen(s) + block->flag.space)), ' '));
		else
			s = ft_strjoin(ft_scs((block->flag.width) - (int)ft_strlen(s),
						' '), s);

	}
	if (block->flag.sharp && (block->flag.spec == 'X' ||
				block->flag.spec == 'x') && block->flag.dot != -1 &&
			ft_strcmp("0", s) && block->flag.zero)
	{
		i = 0;
		if (s[0] == ' ')
		{
			while(s[i] <= 32 && s[i])
				i++;
			tmp = s;		
		}
		if (block->flag.spec == 'X')
			s = ft_strjoin("0X", s + i);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0x", s + i);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0", s + i);
		if (i)
		{
			tmp = ft_strndup(tmp, i);
			s = ft_strjoin(tmp, s);
		}
	}
	return (s);
}

char		*ft_applyflagbegin(t_case *block, char *s, int *hey, int *sign)
{
	if(hey)
		*hey = 1;

	//	*sign = 0;
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

char		*ft_applyflag(t_case *block, char *s)
{
	int sign;
	int hey;

	sign = 0;
	hey = 0;
	if (ft_strequ("0", s) && block->flag.dot == -2)
		block->flag.dot = -1;
	if (block->flag.neg)
		block->flag.space = 0;
	if (block->flag.dot)
		s = ifdot(block, s, sign, &hey);
	s = ft_applyflagbegin(block, s, &hey, &sign);
	s = applyflagtwo(block, s, sign);
	if (block->flag.zero && block->flag.spec != 's' && block->flag.spec != 'c'
			&& block->flag.dot == 0)
		s = ft_strjoin(ft_scs(block->flag.width - (int)ft_strlen(s), '0'), s);
	if (block->flag.less && !block->flag.zero)
		s = ft_strjoin(s, ft_scs((block->flag.width) - ((int)ft_strlen(s) + block->flag.space), ' '));
	s = ft_applyflagthree(block, s);
	if (block->flag.space && !block->flag.plus)
		s = ft_strjoin(" ", s);
	if ((sign || block->flag.neg) && (block->flag.zero || block->flag.dot))
	{
		s = ft_deletechar(s, '-');
		s = ft_putspace(block, s);
	}
	else if (block->flag.plus && !sign && s[0] != '-')
		s = ft_putspacetwo(block, s);
	return (s);
}

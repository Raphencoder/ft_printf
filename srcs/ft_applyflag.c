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
		{
			tmp = ft_scs((block->flag.width) - (((int)ft_strlen(s) + block->flag.space)), ' ');
			s = ft_strjoin(s, tmp);
		}
		else
		{
			tmp = ft_scs((block->flag.width) - (int)ft_strlen(s),
					' ');
			s = ft_strjoin(tmp, s);
		}
		ft_strdel(&tmp);

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
		else
			s = ft_strdup(s);
		if (i)
		{
			tmp = ft_strndup(tmp, i);
			s = ft_strjoin(tmp, s);
			ft_strdel(&tmp);
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
	char *tmp;
	char	*leaked;
	sign = 0;
	hey = 0;
	if (ft_strequ("0", s) && block->flag.dot == -2)
		block->flag.dot = -1;
	if (block->flag.neg)
		block->flag.space = 0;
	if (block->flag.dot)
		s = ifdot(block, s, sign, &hey);
	tmp = s;
	s = ft_applyflagbegin(block, tmp, &hey, &sign);
	if (!ft_strequ(tmp, s))
		ft_strdel(&tmp);
	tmp = s;
	s = applyflagtwo(block, s, sign);
	if (tmp != s)
		ft_strdel(&tmp);
	if (block->flag.zero && block->flag.spec != 's' && block->flag.spec != 'c'
			&& block->flag.dot == 0)
	{
		tmp = s;
		leaked = ft_scs(block->flag.width - (int)ft_strlen(s), '0');
		s = ft_strjoin(leaked, tmp);
		ft_strdel(&leaked);
		if (tmp != s)
			ft_strdel(&tmp);
	}
	if (block->flag.less && !block->flag.zero)
	{
		tmp = s;
		leaked = ft_scs((block->flag.width) - ((int)ft_strlen(s) + block->flag.space), ' ');
		s = ft_strjoin(s, leaked);
		ft_strdel(&tmp);
		ft_strdel(&leaked);
	}
	tmp = s;
	s = ft_applyflagthree(block, s);
	if (tmp != s)
		ft_strdel(&tmp);
	if (block->flag.space && !block->flag.plus)
	{
		tmp = s;
		s = ft_strjoin(" ", s);
		ft_strdel(&tmp);
	}
	if ((sign || block->flag.neg) && (block->flag.zero || block->flag.dot))
	{
		s = ft_deletechar(s, '-');
		s = ft_putspace(block, s);
	}
	else if (block->flag.plus && !sign && s[0] != '-')
	{
		tmp = s;
		s = ft_putspacetwo(block, tmp);
		if (s != tmp)
			ft_strdel(&tmp);
	}
	return (s);
}

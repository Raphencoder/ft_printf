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

char		*ft_applyzeroless(t_case *block, char *s)
{
	char *tmp;
	char *leaked;

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
		leaked = ft_scs((block->flag.width) -
((int)ft_strlen(s) + block->flag.space), ' ');
		s = ft_strjoin(s, leaked);
		ft_strdel(&tmp);
		ft_strdel(&leaked);
	}
	return (s);
}

void		beginif(t_case *block, char *s)
{
	if (ft_strequ("0", s) && block->flag.dot == -2)
		block->flag.dot = -1;
	if (block->flag.neg)
		block->flag.space = 0;
}

char		*ft_endapply(t_case *block, char *s, char *tmp, int sign)
{
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

char		*ft_applyflag(t_case *block, char *s)
{
	int		sign;
	int		hey;
	char	*tmp;

	hey = 0;
	sign = 0;
	beginif(block, s);
	if (block->flag.dot)
		s = ifdot(block, s, sign, &hey);
	tmp = s;
	s = ft_applybegin(block, tmp, &hey, &sign);
	if (!ft_strequ(tmp, s))
		ft_strdel(&tmp);
	tmp = s;
	s = applyflagtwo(block, s, sign);
	if (tmp != s)
		ft_strdel(&tmp);
	s = ft_applyzeroless(block, s);
	tmp = s;
	s = ft_applyflagthree(block, s);
	if (tmp != s)
		ft_strdel(&tmp);
	s = ft_endapply(block, s, tmp, sign);
	return (s);
}

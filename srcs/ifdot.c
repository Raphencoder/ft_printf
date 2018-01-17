/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifdot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/17 13:15:32 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ifdottwo(t_case *block, char *s, int sign)
{
	char	*tmp;
	char	*leaked;

	if (sign)
		sign = 1;
	if (block->flag.width > block->flag.dot)
	{
		tmp = s;
		if (block->flag.sharp)
		{
			leaked = ft_scs((block->flag.width - (((int)ft_strlen(s)) + 2)), ' ');
			s = ft_strjoin(leaked, s);
			ft_strdel(&leaked);
		}
		else
		{
			leaked = ft_scs((block->flag.width - ((int)ft_strlen(s) + block->flag.plus)), ' ');
			s = ft_strjoin(leaked, s);
			ft_strdel(&leaked);
		}
		ft_strdel(&tmp);
	}
	return (s);
}

char		*ifdot(t_case *block, char *s, int sign, int *hey)
{
	char	*tmp;
	char	*leaked;

	if (block->flag.spec == 's' || block->flag.spec == 'c')
	{
		if (block->flag.dot < (int)ft_strlen(s))
		{
			tmp = s;
			s = ft_strndup(s, block->flag.dot);
			ft_strdel(&tmp);
		}
	}
	else
	{
		tmp = s;
		if (block->flag.neg && block->flag.dot > (int)ft_strlen(s) - 1)
		{
			leaked = ft_scs((block->flag.dot - ((int)ft_strlen(s) - 1)), '0');
			s = ft_strjoin(leaked, s);
			ft_strdel(&leaked);
		}
		else if (block->flag.dot > (int)ft_strlen(s))
		{
			leaked = ft_scs((block->flag.dot - ((int)ft_strlen(s))), '0');
			s = ft_strjoin(leaked, s);
			ft_strdel(&leaked);
		}
		else
			s = ft_strdup(s);
		if (tmp != s)
			ft_strdel(&tmp);
	}
	if (block->flag.zero && block->flag.width)
	{
		*hey = 1;
		s = ifdottwo(block, s, sign);
	}
	return (s);
}

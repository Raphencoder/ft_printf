/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:08:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 19:42:37 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ifdottwo(t_case *block, char *s, int sign)
{
	char	*tmp;
	char	*leak;

	if (sign)
		sign = 1;
	if (block->flag.width > block->flag.dot)
	{
		tmp = s;
		if (block->flag.sharp)
		{
			leak = ft_scs((block->flag.width - (((int)ft_strlen(s)) + 2)), ' ');
			s = ft_strjoin(leak, s);
			ft_strdel(&leak);
		}
		else
		{
			leak = ft_scs((block->flag.width - ((int)ft_strlen(s) +
			block->flag.plus)), ' ');
			s = ft_strjoin(leak, s);
			ft_strdel(&leak);
		}
		ft_strdel(&tmp);
	}
	return (s);
}

void		ifdotthree(t_case *block, char **s)
{
	char	*leaked;
	char	*tmp;

	tmp = *s;
	if (block->flag.neg && block->flag.dot > (int)ft_strlen(*s) - 1)
	{
		leaked = ft_scs((block->flag.dot - ((int)ft_strlen(*s) - 1)), '0');
		*s = ft_strjoin(leaked, *s);
		ft_strdel(&leaked);
	}
	else if (block->flag.dot > (int)ft_strlen(*s))
	{
		leaked = ft_scs((block->flag.dot - ((int)ft_strlen(*s))), '0');
		*s = ft_strjoin(leaked, *s);
		ft_strdel(&leaked);
	}
	else
		*s = ft_strdup(*s);
	if (tmp != *s)
		ft_strdel(&tmp);
}

char		*ifdot(t_case *block, char *s, int sign, int *hey)
{
	char	*tmp;

	if (block->flag.spec == 's' || block->flag.spec == 'c')
	{
		if (block->flag.dot == -1)
		{
			s = ft_strdup("");
			if (block->flag.width)
				s = ft_scs(block->flag.width, ' ');
		}
		else if (block->flag.dot < (int)ft_strlen(s))
		{
			tmp = s;
			s = ft_strndup(s, block->flag.dot);
			ft_strdel(&tmp);
		}
	}
	else
		ifdotthree(block, &s);
	if (block->flag.zero && block->flag.width)
	{
		*hey = 1;
		s = ifdottwo(block, s, sign);
	}
	return (s);
}

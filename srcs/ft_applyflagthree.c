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

void		ft_move(char *s, int *i)
{
	i = 0;
	if (s[0] == ' ')
	{
		while (s[*i] <= 32 && s[*i])
			*i = *i + 1;
	}
}

char		*transforms(t_case *block, char *s, char *tmp)
{
	int i;

	i = 0;
	if (block->flag.sharp && (block->flag.spec == 'X' ||
block->flag.spec == 'x') && block->flag.dot != -1 &&
ft_strcmp("0", s) && block->flag.zero)
	{
		ft_move(s, &i);
		tmp = s;
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

char		*ft_applyflagthree(t_case *block, char *s)
{
	char *tmp;

	if (block->flag.width && !block->flag.zero)
	{
		tmp = ft_scs((block->flag.width) - (((int)ft_strlen(s) +
(block->flag.less ? block->flag.space : 0))), ' ');
		if (block->flag.less)
			s = ft_strjoin(s, tmp);
		else
			s = ft_strjoin(tmp, s);
		ft_strdel(&tmp);
	}
	tmp = NULL;
	s = transforms(block, s, tmp);
	return (s);
}

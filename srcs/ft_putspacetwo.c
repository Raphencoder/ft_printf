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

#include "ft_printf.h"

char	*ft_putspacetwo(t_case *block, char *s)
{
	int		i;
	char	*tmp;
	char	*leaked;

	i = 0;
	if (block->flag.width)
	{
		while (s[i] <= 32 && s[i])
			i++;
		leaked = s;
		s = ft_strjoin("+", s + i);
		tmp = ft_strndup(leaked, i);
		ft_strdel(&leaked);
		leaked = s;
		s = ft_strjoin(tmp, s);
		ft_strdel(&tmp);
		ft_strdel(&leaked);
	}
	else
		s = ft_strjoin("+", s);
	return (s);
}

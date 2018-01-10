/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choosebase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:38:05 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/09 18:36:27 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putspacetwo(t_case *block, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (block->flag.width)
	{
		while (s[i] <= 32 && s[i])
			i++;
		tmp = s;
		s = ft_strjoin("+", s + i);
		tmp = ft_strndup(tmp, i);
		s = ft_strjoin(tmp, s);
	}
	else
		s = ft_strjoin("+", s);
	return (s);
}

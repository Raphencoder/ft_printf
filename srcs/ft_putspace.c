/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:40:39 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/09 18:31:48 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_putspace(t_case *block, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (block)
		block->content = block->content;
	while (s[i] <= 32 && s[i])
		i++;
	tmp = s;
	s = ft_strjoin("-", s + i);
	tmp = ft_strndup(tmp, i);
	s = ft_strjoin(tmp, s);
	return (s);
}

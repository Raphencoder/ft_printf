/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:34:04 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/28 00:58:23 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlst(t_case *start)
{
	static int size;

	if ((*start).next != NULL)
		ft_printlst((*start).next);
	if (((int)(*start).content_size) == ((int)-1))
	{
		if (start->flag.width)
		{
			ft_putstr(ft_scs(start->flag.width - 1, ' '));
			size = size + (start->flag.width - 1);
		}
		ft_putchar(0);
		size = size + 1;
		return (size);
	}
	size = size + (ft_strlen((*start).content));
	ft_putstr((*start).content);
	return (size);
}

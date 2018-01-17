/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:34:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 19:30:22 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagwidth(t_case *start, int *size)
{
	ft_putstr(ft_scs(start->flag.width - 1, ' '));
	*size = *size + (start->flag.width - 1);
}

int		ft_flagwstr(t_case *start, int *size)
{
	*size = *size + ft_putwstr(start->flag.wstr);
	return (*size + ft_printlst(start->next));
}

int		ft_printlst(t_case *start)
{
	int size;

	size = 0;
	if (start == 0)
		return (0);
	if (((int)start->content_size) == ((int)-1))
	{
		if (start->flag.width)
			ft_flagwidth(start, &size);
		ft_putchar(0);
		size = size + 1;
		return (size + ft_printlst(start->next));
	}
	if (start->flag.wstr)
		return (ft_flagwstr(start, &size));
	if (start->flag.c)
	{
		size = size + ft_putwchar(start->flag.c);
		return (size + ft_printlst(start->next));
	}
	else
		ft_putstr(start->content);
	size = size + (ft_strlen(start->content));
	return (size + ft_printlst(start->next));
}

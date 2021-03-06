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

/*
**	This is the main function, it call the ft_fill function to put the format
**	string into linked list and then callthe findspec unctions to look for
**	for the spec in the content of the different link of the linked list.
*/

int		ft_printf(char const *restrict format, ...)
{
	va_list arglst;
	t_case	*start;
	t_case	*block;
	int		size;
	t_case	*tmp;

	va_start(arglst, format);
	if (ft_strequ(format, ""))
		return (0);
	start = ft_fillstr((char*)format);
	block = start;
	if (!block)
		return (0);
	ft_call(block, arglst);
	size = ft_printlst(start);
	while (start != NULL)
	{
		tmp = start;
		start = start->next;
		ft_strdel(&tmp->content);
		ft_memdel((void**)&tmp);
	}
	va_end(arglst);
	return (size);
}

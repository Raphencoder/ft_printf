/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:08:44 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/14 21:39:10 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This is the main function, it call the ft_fill function to put the format
**	string into linked list and then callthe findspec unctions to look for
**	for the spec in the content of the different link of the linked list.
 */

int		ft_printf(char const * restrict format, ...)
{
	va_list arglst;
	t_case	**start;
	t_case	*block;

	va_start(arglst, format);
	start = ft_fillstr((char*)format);
	block = *start;
	while (block->next != NULL)
	{
		block->content = ft_findspec(block, arglst);
		block->content = ft_applyflag(block, arglst);
		block = block->next;
	}
//	block->content = ft_findspec(block, arglst);
//	block->content = ft_applyflag(block, arglst);
	ft_printlst(*start);
	va_end(arglst);
	return (0);
}

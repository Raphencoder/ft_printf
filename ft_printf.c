/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:08:44 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/18 20:51:33 by rkrief           ###   ########.fr       */
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
//	ft_printlst(*start);
//	while (block->next != NULL)
//	{
//		block->content = ft_findspec(block, arglst);
//		block->content = ft_applyflag(block, block->content);
//		block = block->next;
//	}
//	block->content = ft_findspec(block, arglst);
//	if (((block->content)[0]) == '%')
//			block->content = ft_applyflag(block, block->content);
	ft_call(block, arglst);
	ft_printlst(*start);
	ft_putchar('\n');
	va_end(arglst);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:08:44 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/21 12:24:50 by rkrief           ###   ########.fr       */
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
	int		size;

	va_start(arglst, format);
	if (ft_strequ(format, ""))
		return (0);
	start = ft_fillstr((char*)format);
	block = *start;
	ft_call(block, arglst);
	size = ft_printlst(*start);
	va_end(arglst);
	return (size);
}

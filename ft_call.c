/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:40:24 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/19 14:14:59 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call(t_case *block, va_list arglst)
{
	char *s;

	s = "(null)";
	if (block->next != NULL)
		ft_call(block->next, arglst);
	block->content = ft_findspec(block, arglst);
	if (block->flag.spec == -1)
		return ;
	if (block->content == NULL)
		block->content = ft_strdup(s);
	else if (block->flag.spec)
		block->content = ft_applyflag(block, block->content);
	return ;
}

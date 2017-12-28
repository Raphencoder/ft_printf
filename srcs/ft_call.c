/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:40:24 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/27 23:51:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call(t_case *block, va_list arglst)
{
	static int count;

	if (block->next != NULL)
	{
		ft_call(block->next, arglst);
		count++;
	}
	block->content = ft_findspec(block, arglst);
	if (block->flag.spec == -1)
		return ;
	if (((ft_strequ(block->content, "") || block->content == NULL) && block->flag.spec) && block->next == NULL && count)
		block->content = ft_strdup("(null)");
	else if (block->flag.spec)
		block->content = ft_applyflag(block, block->content);
	return ;
}

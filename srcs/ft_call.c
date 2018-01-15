/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:40:24 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 18:59:35 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call(t_case *block, va_list arglst)
{
	if (block == NULL)
		block = NULL;
	if (!block)
		return ;
	block->content = ft_findspec(block, arglst);
	if (!block->content)
		return ft_call(block->next, arglst);
	if (ft_strequ(block->content, "-nUlLl'-"))
		return ft_call(block->next, arglst);
	if ((block->content)[0] == '-') 
		block->flag.neg = 1;
	if (block->flag.spec == -1)
		return ft_call(block->next, arglst);
	if (((ft_strequ(block->content, "") || block->content == NULL) &&
				block->flag.spec) && block->next == NULL)
		block->content = ft_strdup("(null)");
	else if (block->flag.spec)
	{
		if (block->flag.spec == '%')
		{
			block->flag.dot = 0;
			block->flag.space = 0;
		}
		block->content = ft_applyflag(block, block->content);
	}
	ft_call(block->next, arglst);
	return ;
}

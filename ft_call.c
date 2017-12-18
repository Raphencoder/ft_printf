/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:40:24 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/18 19:27:05 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call(t_case *block, va_list arglst)
{
	if (block->next != NULL)
		ft_call(block->next, arglst);
	block->content = ft_findspec(block, arglst);
	if (block->flag.spec)
		block->content = ft_applyflag(block, block->content);
	return ;
}

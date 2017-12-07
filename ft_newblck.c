/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newblck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:09:39 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/06 16:19:19 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_newblck(char *str, int i, t_case **start)
{
	t_case	*block;

	if ((block = (t_case*)ft_memalloc(sizeof(t_case))) == NULL)
		return ;
	block->content = ft_strndup(str, i);
	block->next = *start;
	*start = block;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newblck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:09:39 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/20 20:06:17 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function create a new link with the string passed in parameter, the 
**	content of the link start at the 'i' position, and the t_case **start
**	is the beginning of the linked list
*/

void	ft_newblck(char *str, int head, int len, t_case **start)
{
	t_case	*block;

	if ((block = (t_case*)ft_memalloc(sizeof(t_case))) == NULL)
		return ;
	block->content = ft_strsub(str, head, len);
	ft_putendl(block->content);
	block->next = *start;
	*start = block;
}

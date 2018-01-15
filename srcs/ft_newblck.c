/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newblck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:09:39 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 15:00:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function create a new link with the string passed in parameter, the
**	content of the link start at the 'i' position, and the t_case **start
**	is the beginning of the linked list
*/

t_case	*ft_newblck(char *str, int head, int len)
{
	t_case	*block;

	if ((block = ft_memalloc(sizeof(t_case))) == NULL)
		return (0);
	block->content = ft_strsub(str, head, len);
	block->next = 0;
	return (block);
}

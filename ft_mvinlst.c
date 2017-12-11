/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvinlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:22:27 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 19:24:39 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function apply the function ft_putflags for each link of the link 
**	chain.
*/

void	ft_mvinlst(t_case *block)
{	
	int	i;

	i = 0;
	if ((block->content)[i] == '%')
		ft_putflags(block);
	if (block->next != NULL)
		ft_mvinlst(block->next);
}

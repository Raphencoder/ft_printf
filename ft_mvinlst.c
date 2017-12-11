/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvinlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:22:27 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 11:30:21 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mvinlst(t_case *block)
{	
	ft_putflags(block);
	if (block->next != NULL)
		ft_mvinlist(block->next);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:34:04 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/14 21:34:33 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printlst(t_case *start)
{
	if ((*start).next != NULL)
		ft_printlst((*start).next);
	ft_putstr((*start).content);
}

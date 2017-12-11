/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:30:46 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 11:56:10 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putflags(t_case block)
{
	int	i;
	int	open;

	open = 0;
	i = 0;
	while ((block->content)[i])
	{
		if (ft_isdigit((block->content)[i]) && open == 1)
			flag->width = 0;
		if ((block->content)[i] == '+')
			flag->plus = 1;	
		if ((block->content)[i] == '-')
			flag->less = 1;	
		if ((block->content)[i] == '#')
			flag->sharp = 1;	
		if ((block->content)[i] == '0')
			flag->zero = 1;	
		if ((block->content)[i] == ' ')
			flag->space = 1;
		while (ft_isdigit((block->content)[i]) == 1)
		{
			flag->width = (flag->width * 10) + ft_atoi((block->content)[i++]);
			open = 1;
		}
		i++;
	}	
}

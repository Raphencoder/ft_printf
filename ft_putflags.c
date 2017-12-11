/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:30:46 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 17:44:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putflags(t_case *block)
{
	int	i;
	int	j;
	char *str;

	i = 0;
	j = 0;
	while ((block->content)[i])
	{
		if ((block->content)[i] == '+')
			block->flag.plus = 1;	
		if ((block->content)[i++] == '.')
		{
			block->flag.dot = ft_atoi(block->content + i);
			while(ft_isdigit((block->content)[i]))
				i++;
			i--;
		}
		else if ((block->content)[i] == '-')
			block->flag.less = 1;	
		else if ((block->content)[i] == '#')
			block->flag.sharp = 1;	
		else if ((block->content)[i] == '0')
			block->flag.zero = 1;	
		else if ((block->content)[i] == ' ')
			block->flag.space = 1;
		if (ft_isdigit((block->content)[i]) == 1)
		{
			block->flag.width = ft_atoi(block->content + i);
			while(ft_isdigit((block->content)[i]))
				i++;
			i--;
		}
		i++;
	}	
}

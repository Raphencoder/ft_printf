/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:30:46 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 13:52:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putflags(t_case *block)
{
	int	i;
	char *str;

	i = 0;
	while ((block->content)[i])
	{
		if ((block->content)[i] == '+')
			block->flag.plus = 1;	
		if ((block->content)[i] == '-')
			block->flag.less = 1;	
		if ((block->content)[i] == '#')
			block->flag.sharp = 1;	
		if ((block->content)[i] == '0')
			block->flag.zero = 1;	
		if ((block->content)[i] == ' ')
			block->flag.space = 1;
		if (ft_isdigit((block->content)[i]) == 1)
			block->flag.width = ft_atoi(1);
			str = ft_strndup((block->content), i);
			printf("WATCHOUT = %s\n", str);
		i++;
	}	
}

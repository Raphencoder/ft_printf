/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:23:20 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/18 17:21:58 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function will take the original string 'format' and divide it in link
**	chain.
**	When the function spot the '%', it created a new link.
**	It calls the function mvinlst who will help to set the flags.
*/


t_case		**ft_fillstr(char *format)
{
	int	i;
	char	*str;
	char 	*tmp;
	t_case **start;

	start = (t_case**)ft_memalloc(sizeof(t_case*));
	i = 0; 
	str = ft_strdup(format);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			i++;
		if (i != 0)
		{
			ft_newblck(str, i, start);
			str = str + i;
			i = 1;
		}
		if (str[i] == '%')
			i++;
		while (!(ft_isspec(str[i])) && str[i])
			i++;
		i++;
		ft_newblck(str, i, start);
		str = str + i;
		i = 0;
		i++;
	}
	free(tmp);
//	ft_mvinlst(*start);
	return (start);
}

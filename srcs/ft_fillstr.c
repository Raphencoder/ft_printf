/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:23:20 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/20 22:10:41 by rkrief           ###   ########.fr       */
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
	int j;
	char	*str;
	t_case **start;
	int	flag;

	flag = 0;
	start = (t_case**)ft_memalloc(sizeof(t_case*));
	i = 0; 
	str = ft_strdup(format);
	while (str[i])
	{
		flag = 0;
		j = i;
		while (str[i] != '%' && str[i])
			i++;
		if (i != 0)
		{
			flag = flag + i - j;
			ft_newblck(str, j, (i - j), start);
			j = i;
		}
		if (str[i + 1] == '%')
		{
			flag = flag + 2;
			ft_newblck("%%", 0, 2, start);
			i += 2;
			j = i;
		}
		if (str[i] == '%')
			i++;
		while (!ft_isspec(str[i]) && str[i])
			i++;
		if (ft_isspec(str[i]))
		{
			flag = flag + i - j + 1;
			ft_newblck(str, j, (i - j + 1), start);
			j = i;
			i++;
		}
		str = str + flag;
		i = 0;
	}
	return (start);
}

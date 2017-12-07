/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:23:20 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/07 16:42:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_filllst(char *str)
{
	int	i;
	char	*str;
	char 	*tmp;
	t_case **start;

	start = (t_case**)ft_memalloc(sizeof(t_case*));
	i = 0; 
	str = ft_strdup(format);
	tmp = str;
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
		while (!(ft_isspec(str[i])) && str[i])
			i++;
		i++;
		ft_newblck(str, i, start);
		str = str + i;
		i = 0;
		i++;
	}
	free(tmp);
	ft_printlst(*start);
	return (0);
}

int main()
{
	ft_printf("helloworld%232%+23zdwhatsup");
	return (0);
}

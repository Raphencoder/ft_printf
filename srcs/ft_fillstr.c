/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:23:20 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/14 12:07:16 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function will take the original string 'str' and divide it in link
**	chain.
**	When the function spot the '%', it created a new link.
**	It calls the function mvinlst who will help to set the flags.
*/

void		ft_fillstrtwo(char *str, int *i, int *j, t_case **start)
{
	if (str[*i + 1] == '%')
	{
		ft_newblck("%%", 0, 2, start);
		*i = *i + 2;
		*j = *i;
	}
	if (str[*i] == '%')
		*i = *i + 1;
	while (!ft_isspec(str[*i]) && str[*i])
		*i = *i + 1;
	if (ft_isspec(str[*i]))
	{
		ft_newblck(str, *j, (*i - *j + 1), start);
		*j = *i;
		*i = *i + 1;
	}
}

void		ft_initialize(int *i, int *j, int *flag)
{
	*i = 0;
	*j = 0;
	*flag = 0;
}

t_case		**ft_fillstr(char *str)
{
	int		i;
	int		j;
	t_case	**start;
	t_case	*block;
	int		flag;

	start = (t_case**)ft_memalloc(sizeof(t_case*));
	if (ft_checkstr(str))
	{
			block = (t_case*)ft_memalloc(sizeof(t_case));
			if (ft_strequ(" ", ft_checkstr(str)))
				{
					return (NULL);
				}
			else
			{
					block->content = (ft_checkstr(str));
					block->flag.dot = ft_strlen(ft_checkstr(str));
					*start = block;
					return (start);
			}
	}
	ft_initialize(&i, &j, &flag);
	while (str[i])
	{
		while (str[i] && str[i] != '%' && str[i])
			i++;
		if (i != 0)
		{
			ft_newblck(str, j, (i - j), start);
			j = i;
		}
		ft_fillstrtwo(str, &i, &j, start);
		str = str + (i - flag);
		ft_initialize(&i, &j, &flag);
	}
	return (start);
}

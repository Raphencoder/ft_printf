/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:23:20 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/16 19:13:12 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function will take the original string 'str' and divide it in link
**	chain.
**	When the function spot the '%', it created a new link.
**	It calls the function mvinlst who will help to set the flags.
*/

void		ft_fillstrtwo(char *str, int *i, int *j, t_case **curr)
{
	if (str[*i] == 0)
		return ;
	if (str[*i + 1] == '%')
	{
		(*curr)->next = ft_newblck("%%", 0, 2);
		*curr = (*curr)->next;
		*i = *i + 2;
		*j = *i;
		return ;
	}
	if (str[*i] == '%')
		*i = *i + 1;
	while (!ft_isspec(str[*i]) && str[*i])
		*i = *i + 1;
	if (ft_isspec(str[*i]))
	{
		(*curr)->next = ft_newblck(str, *j, (*i - *j + 1));
		*curr = (*curr)->next;
		*j = *i;
		*i = *i + 1;
	}
}

void		ft_initialize(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

t_case		*ft_fillstr(char *str)
{
	int		i;
	int		j;
	t_case	*start;
	t_case	*curr;

	ft_initialize(&i, &j);
	start = ft_memalloc(sizeof(t_case));
	start->next = 0;
	curr = start;
	while (str[i])
	{
		while (str[i] && str[i] != '%' && str[i])
			i++;
		if (i != 0)
		{
			curr->next = ft_newblck(str, j, (i - j));
			curr = curr->next;
			j = i;
		}
		ft_fillstrtwo(str, &i, &j, &curr);
		str = str + i;
		ft_initialize(&i, &j);
	}
	curr = start->next;
	ft_memdel((void **)&start);
	return (curr);
}

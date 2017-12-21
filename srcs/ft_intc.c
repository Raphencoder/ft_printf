/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:57:44 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/19 17:22:41 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_intc(char c, t_case *block)
{
	char *str;

	if ((str = (char*)ft_memalloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	str[0] = c;
	if (c == 0)
		block->content_size = -1;
	return (str);
}

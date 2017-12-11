/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:34:04 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 17:40:51 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printlst(t_case *start)
{
	if ((*start).next != NULL)
		ft_printlst((*start).next);
	printf("%s\n", ((*start).content));
	printf("plus %d\n", ((*start).flag.plus));
	printf("less %d\n", ((*start).flag.less));
	printf("space %d\n", ((*start).flag.space));
	printf("sharp %d\n", ((*start).flag.sharp));
	printf("zero %d\n", ((*start).flag.zero));
	printf("width %d\n", ((*start).flag.width));
	printf("dot %d\n", ((*start).flag.dot));

}

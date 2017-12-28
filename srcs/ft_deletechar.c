/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <raphaelkriefbm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 00:15:25 by Raphael           #+#    #+#             */
/*   Updated: 2017/12/27 16:26:07 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_deletechar(char *str, char c)
{
			char *tmp;
			int	j;
			int k;
			char *new;

			j = 0;
			k = 0;
			new = (char*)ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
			tmp = str;
			while (tmp[k])
			{
					while (tmp[k] == c && tmp[k])
						k++;
					new[j] = tmp[k];
					j++;
					k++;
			}
			return (new);
}

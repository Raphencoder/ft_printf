/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:08:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 19:42:37 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_minimalize(char *str)
{
	int		i;
	char	*tmp;
	char	*res;

	tmp = 0;
	i = 0;
	while (!ft_isspec(str[i]) && str[i])
		i++;
	if (ft_isspec(str[i]) && (str[i] >= 'A' && str[i] <= 'Z'))
	{
		if (str[i] == 'D')
			tmp = ft_strdup("ld");
		else if (str[i] == 'U')
			tmp = ft_strdup("lu");
		else if (str[i] == 'O')
			tmp = ft_strdup("lo");
		else
			tmp = ft_strdup(str);
	}
	else
		tmp = ft_strdup(str);
	res = tmp;
	free(str);
	return (res);
}

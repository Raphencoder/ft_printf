/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takespec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:41:00 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/18 19:48:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_takespec(char *s)
{
	int i;

	i = 0;
	while (!ft_isspec(s[i]))
		i++;
	return (s[i]);
}

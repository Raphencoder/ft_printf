/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:22:29 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/20 22:12:14 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int main()
{
	uintmax_t i;

	i = 6001;
	   printf("hello%s\n%%%ju\n", "salut", i);
	ft_printf("hello%s\n%%%ju\n", "salut", i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:22:29 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/10 18:30:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned long int i;

	i = 4294967296;
	char c;
	c = '\0';
//	printf("p %d\n\n", printf("p %hU\n", i));
//	printf("\n\n");
//	printf("f %d\n\n", ft_printf("f %hU\n", i));
	printf("%U", 4294967296);
	return (0);
}


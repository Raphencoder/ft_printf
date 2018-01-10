/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:22:29 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/10 15:31:52 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int main()
{
	short int i;

	i = -9645;
	char c;
	c = '\0';
	printf("p %d\n\n", printf("p %x\n\n", 0));
	printf("\n\n");
	printf("f %d\n\n", ft_printf("f %x\n\n", 0));
	return (0);
}

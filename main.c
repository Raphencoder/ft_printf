/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:22:29 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/11 17:48:40 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int main()
{

//	printf("p %d\n\n", printf("p %hU\n", i));
//	printf("\n\n");
	printf("p %d\n\n", printf("p @moulitest: %#10.8o\n", 42));
	printf("f %d\n\n", ft_printf("f @moulitest: %#10.8o\n", 42));
//	printf("%U", 4294967296);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:22:29 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 20:02:30 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <locale.h>
#include <stdio.h>

int main()
{
	long l = 2147483647;
	long long ll = 9223372036854775807;
	char c = 0;
	int i = 3;
	intmax_t im = 9223372036854775807;

	setlocale(LC_ALL, "");
	printf("f %d\n" , ft_printf("f %p\n\n", &i));
	printf("p %d\n" , printf("p %p\n\n", &i));
	

	//	printf("p %d\n\n", printf("p %hU\n", i));
	//	printf("%%%%\n");
	//	printf("\n");
	//	ft_printf("%%%%\n");
	return (0);
}


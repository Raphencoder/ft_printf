/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:04:26 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/08 13:07:07 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t wc)
{
	if (wc <= 0x7F)
		ft_putchar(wc);
	else if (wc <= 0x7FF)
	{
		ft_putchar((wc >> 6) + 0xC0);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putchar((wc >> 12) + 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putchar((wc >> 18) + 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
}

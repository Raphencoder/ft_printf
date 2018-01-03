/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:10:46 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/02 15:10:53 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoalld(long long int nb)
{	
	char	*str;
	int		len_int;
	int		m;

	m = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len_int = ft_len_int(nbr);
	if (nbr < 0)
		m = 1;
	str = ft_strnew(len_int + m);
	if (str == NULL)
		return (NULL);
	nbr = ABS(nbr);
	str[len_int + 1] = '\0';
	if (m == 0)
		len_int--;
	str = ft_while_itoa(str, len_int, nbr);
	if (m == 1)
		str[0] = '-';
	return (str);
}
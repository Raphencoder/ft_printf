/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islength.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:17:51 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/07 16:23:37 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islength(char *str, int i)
{
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z' 
			|| str[i] == 't' || str[i] == 'L')
	{
		if (str[i + 1] == 'h' || str[i + 1] == 'l')
			return (1);
		return (1);
	}
	return (0);
}
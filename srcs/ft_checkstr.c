/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <raphaelkriefbm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:19:15 by Raphael           #+#    #+#             */
/*   Updated: 2018/01/14 11:40:26 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_checkmod(char *str)
{
		int i;
		int flag;

		flag = 0;
		i = 0;
		while (str[i])
		{
			while ((ft_islength(str[i]) || ft_isflag(str[i]) || ft_isspec(str[i])) && str[i])
				i++;
			if (str[i])
			{
					flag++;
					break;
			}
		}
			if (flag)
			{
				if (i == 0)
						return (str);
				str = str + i;
				return (str);
			}
			return (NULL);
}

char		*ft_checkstr(char *str)
{
		int i;
		int mod;
		int	spec;

		spec = 0;
		mod = 0;
		i = 0;
		while (str[i])
		{
				if (str[i] == '%')
						break ;
		}
		if (!str[i + 1])
				return (" ");
		if (ft_checkmod(str + i + 1))
		{
					if (ft_strequ((str + i + 1), ft_checkmod(str + i + 1)))
					{
							while (str[i])
								i++;
							i--;
						return (str + i);
					}
					str = ft_strjoin(str, ft_checkmod(str+ i));
					return (str);
		}
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:58:19 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/10 14:12:52 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This function will identify wich function to call depending on the
**  comparison between the 'str' passed in parameter and the string that i
**	will write.
*/

char	*ft_itoap(intmax_t nb)
{
	intmax_t	clone;
	int			i;
	char		*res;

	i = 0;
	clone = nb;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	res = (char*)ft_memalloc(sizeof(char) * i + 2);
	while (clone >= 10)
	{
		res[i] = (clone % 10) + 48;
		clone = clone / 10;
		i--;
	}
	res[i] = clone + 48;
	return (res);
}

char	*ft_findspectwo(t_case *block, va_list arglst, char *flag, char *s)
{
	if (block->flag.spec == 'd' || block->flag.spec == 'i')
	{
		if (ft_strequ(flag, "ll"))
			return (ft_itoac(va_arg(arglst, long long int)));
		if (ft_strequ(flag, "l"))
			return (ft_itoac(va_arg(arglst, long int)));
		if (!flag)
			return (ft_itoac(va_arg(arglst, int)));
		if (ft_strequ(flag, "j"))
			return (ft_itoac(va_arg(arglst, intmax_t)));
		if (ft_strequ(flag, "z"))
			return (ft_itoac(va_arg(arglst, size_t)));
		else
			return (ft_itoac((short int)va_arg(arglst, int)));
	}
	else if (block->flag.spec == 'u' || block->flag.spec == 'o' ||
block->flag.spec == 'x' || block->flag.spec == 'X' || block->flag.spec == 'p')
	{
		if (ft_strequ(flag, "ll"))
			return (ft_choosebase(s, va_arg(arglst, unsigned long long)));
		if (ft_strequ(flag, "l"))
			return (ft_choosebase(s, va_arg(arglst,  unsigned long)));
		if (!flag)
			return (ft_choosebase(s, va_arg(arglst,  unsigned int)));
		if (ft_strequ(flag, "j"))
			return (ft_choosebase(s, va_arg(arglst, uintmax_t)));
		if (ft_strequ(flag, "z"))
			return (ft_choosebase(s, va_arg(arglst, unsigned int)));
		else
			return (ft_choosebase(s, (unsigned short)va_arg(arglst, unsigned int)));
	}
	else if (ft_strequ(s, "c") || (ft_strequ(s, "lc")))
		return (ft_intc(va_arg(arglst, int), block));
	return (NULL);
}

char	*ft_minimalize(char *str)
{
	int		i;
	char	*tmp;
	char	*res;

	tmp = str;
	i = 0;
	while (!ft_isspec(str[i]) && str[i])
		i++;
	if (ft_isspec(str[i]) && (str[i] >= 'A' && str[i] <= 'Z'))
	{
		if (str[i] == 'X')
			str[i] = 'X';
		else
			str[i] = str[i] + 32;
	}
	res = ft_strdup(str);
	free(str);
	return (res);
}

char	*ft_findspec(t_case *block, va_list arglst)
{
	char	*s;
	char	*flag;

	ft_putflags(block);
	if (!block->flag.spec)
		return (block->content);
	s = ft_grepspec(block->content);
	s = ft_minimalize(s);
	if (block->flag.spec)
		block->flag.spec = ft_takespec(s);
	flag = ft_takeflag(s);
	if (s == NULL)
		return (block->content);
	if (ft_strequ(s, "%"))
		return ("%");
	else if (ft_strequ(s, "s") || ft_strequ(s, "ls"))
	{
		s = va_arg(arglst, char*);
		if (s == NULL)
			return ("(null)");
		else
			return (s);
	}
	return (ft_findspectwo(block, arglst, flag, s));
	return (0);
}

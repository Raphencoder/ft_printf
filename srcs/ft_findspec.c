/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:58:19 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/16 19:06:42 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
 **	This function will identify which function to call depending on the
 **  comparison between the 'str' passed in parameter and the string that i
 **	will write.
 */

char	*ft_itoap(long long nb)
{
	long long	clone;
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
	if (block->flag.spec == 'u' && block->flag.space)
		block->flag.space = 0;
	if (block->flag.spec == 'u' && block->flag.plus)
		block->flag.plus = 0;
	if (block->flag.spec == 'd' || block->flag.spec == 'i')
	{
		free(s);
		if (ft_strequ(flag, "ll"))
			return (ft_itoac(va_arg(arglst, long long int)));
		if (ft_strequ(flag, "l"))
			return (ft_itoac(va_arg(arglst, long int)));
		if (!flag)
			return (ft_itoac(va_arg(arglst, int)));
		if (ft_strequ(flag, "j"))
			return (ft_itoac(va_arg(arglst, long long)));
		if (ft_strequ(flag, "z"))
			return (ft_itoac(va_arg(arglst, size_t)));
		if (ft_strequ(flag, "hh"))
			return (ft_itoac((char)va_arg(arglst, int)));
		else
			return (ft_itoac((short int)va_arg(arglst, int)));
	}
	else if (block->flag.spec == 'u' || block->flag.spec == 'o' ||
			block->flag.spec == 'x' || block->flag.spec == 'X' || block->flag.spec == 'p')
	{
		if (ft_strequ(flag, "ll"))
			return (ft_choosebase(s, va_arg(arglst, unsigned long long), flag));
		if (ft_strequ(flag, "l"))
			return (ft_choosebase(s, (unsigned long int)va_arg(arglst, unsigned long int), flag));
		if (!flag)
			return (ft_choosebase(s, va_arg(arglst, unsigned long long int), flag));
		if (ft_strequ(flag, "j"))
			return (ft_choosebase(s, va_arg(arglst, uintmax_t), flag));
		if (ft_strequ(flag, "z"))
			return (ft_choosebase(s, va_arg(arglst, unsigned int), flag));
		if (ft_strequ(flag, "h"))
			return (ft_choosebase(s, (unsigned short)va_arg(arglst, int), flag));

		else
			return (ft_choosebase(s, (unsigned short)va_arg(arglst, unsigned int), flag));
	}
	else if (ft_strequ(s, "C") || (ft_strequ(s, "lc") || ft_strequ(s, "c")))
	{
		if (ft_strequ(s, "c"))
			return (ft_intc(va_arg(arglst, int), block));
		block->flag.c = va_arg(arglst, wchar_t);
		return ("-nUlLl'-");
	}
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
		if (str[i] == 'D')
			tmp = ft_strdup("ld");
		else if (str[i] == 'U')
			tmp = ft_strdup("lu");
		else if (str[i] == 'O')
			tmp = ft_strdup("lo");
	}
	if (tmp)
	{
		res = ft_strdup(tmp);
		free(tmp);
		return (res);
	}
	return (str);
}

char	*ft_findspec(t_case *block, va_list arglst)
{
	char	*s;
	char	*flag;
	char *tmp;

	ft_putflags(block);
	if (!block->flag.spec)
		return (block->content);
	s = ft_grepspec(block->content);
	free(block->content);
	flag = ft_takeflag(s);
	tmp = s;
	s = ft_minimalize(s);
	if (!ft_strequ(tmp, s))
		free(tmp);
	if (block->flag.spec)
		block->flag.spec = ft_takespec(s);
	if (s == NULL)
		return (block->content);
	if (ft_strequ(s, "%"))
		return ("%");
	if (ft_strequ(s, "S") || ft_strequ(s, "ls"))
	{
		block->flag.wstr = va_arg(arglst, wchar_t*);
		if (s == NULL)
			return ("(null)");
		else
			return ("-nUlLl'-");
	}
	else if (ft_strequ(s, "s"))
	{
		s = va_arg(arglst, char*);
		if (s == NULL)
			return ("(null)");
		else
			return (s);
	}
	return (ft_findspectwo(block, arglst, flag, s));
}

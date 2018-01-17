/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:58:19 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/17 12:49:28 by briviere         ###   ########.fr       */
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
	char	*res;

	res = 0;
	if (block->flag.spec == 'u' && block->flag.space)
		block->flag.space = 0;
	if (block->flag.spec == 'u' && block->flag.plus)
		block->flag.plus = 0;
	if (block->flag.spec == 'd' || block->flag.spec == 'i')
	{
		if (ft_strequ(flag, "ll"))
			res = ft_itoac(va_arg(arglst, long long int));
		else if (ft_strequ(flag, "l"))
			res = ft_itoac(va_arg(arglst, long int));
		else if (!flag)
			res = ft_itoac(va_arg(arglst, int));
		else if (ft_strequ(flag, "j"))
			res = ft_itoac(va_arg(arglst, long long));
		else if (ft_strequ(flag, "z"))
			res = ft_itoac(va_arg(arglst, size_t));
		else if (ft_strequ(flag, "hh"))
			res = ft_itoac((char)va_arg(arglst, int));
		else
			res = ft_itoac((short int)va_arg(arglst, int));
	}
	else if (block->flag.spec == 'u' || block->flag.spec == 'o' ||
			block->flag.spec == 'x' || block->flag.spec == 'X' || block->flag.spec == 'p')
	{
		if (ft_strequ(flag, "ll"))
			res = ft_choosebase(s, va_arg(arglst, unsigned long long), flag);
		else if (ft_strequ(flag, "l"))
			res = ft_choosebase(s, (unsigned long int)va_arg(arglst, unsigned long int), flag);
		else if (!flag)
			res = ft_choosebase(s, va_arg(arglst, unsigned long long int), flag);
		else if (ft_strequ(flag, "j"))
			res = ft_choosebase(s, va_arg(arglst, uintmax_t), flag);
		else if (ft_strequ(flag, "z"))
			res = ft_choosebase(s, va_arg(arglst, unsigned int), flag);
		else if (ft_strequ(flag, "h"))
			res = ft_choosebase(s, (unsigned short)va_arg(arglst, int), flag);
		else
			res = ft_choosebase(s, (unsigned short)va_arg(arglst, unsigned int), flag);
	}
	else if (ft_strequ(s, "C") || (ft_strequ(s, "lc") || ft_strequ(s, "c")))
	{
		if (ft_strequ(s, "c"))
			res = ft_intc(va_arg(arglst, int), block);
		else
		{
			block->flag.c = va_arg(arglst, wchar_t);
			res = ft_strdup("-nUlLl'-");
		}
	}
	return (res);
}

char	*ft_minimalize(char *str)
{
	int		i;
	char	*tmp;
	char	*res;

	tmp = 0;
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
		else
			tmp = ft_strdup(str);
	}
	else
		tmp = ft_strdup(str);
	res = tmp;
	free(str);
	return (res);
}

char	*ft_findspec(t_case *block, va_list arglst)
{
	char	*s;
	char	*flag;
	char	*res;

	res = 0;
	ft_putflags(block);
	if (!block->flag.spec)
		return (block->content);
	s = ft_grepspec(block->content);
	ft_strdel(&block->content);
	flag = ft_takeflag(s);
	s = ft_minimalize(s);
	if (block->flag.spec)
		block->flag.spec = ft_takespec(s);
	if (ft_strequ(s, "%"))
		res = ft_strdup("%");
	else if (ft_strequ(s, "S") || ft_strequ(s, "ls"))
	{
		block->flag.wstr = va_arg(arglst, wchar_t*);
		if (s == NULL)
			res = ft_strdup("(null)");
		else
			res = ft_strdup("-nUlLl'-");
	}
	else if (ft_strequ(s, "s"))
	{
		res = va_arg(arglst, char*);
		if (res == NULL)
			res = ft_strdup("(null)");
		else
			res = ft_strdup(res);
	}
	else
		res = ft_findspectwo(block, arglst, flag, s);
	ft_strdel(&flag);
	ft_strdel(&s);
	return (res);
}

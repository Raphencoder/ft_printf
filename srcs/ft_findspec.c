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
**	comparison between the 'str' passed in parameter and the string that i
**	will write.
*/

char	*ifddori(va_list arglst, char *flag)
{
	char *res;

	res = 0;
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
	return (res);
}

char	*ifnotdori(va_list arglst, char *flag, char *s)
{
	char *res;

	res = 0;
	if (ft_strequ(flag, "ll"))
		res = ft_choosebase(s, va_arg(arglst, unsigned long long), flag);
	else if (ft_strequ(flag, "l"))
		res = ft_choosebase(s, va_arg(arglst, unsigned long int), flag);
	else if (!flag)
		res = ft_choosebase(s, va_arg(arglst, unsigned long long int), flag);
	else if (ft_strequ(flag, "j"))
		res = ft_choosebase(s, va_arg(arglst, uintmax_t), flag);
	else if (ft_strequ(flag, "z"))
		res = ft_choosebase(s, va_arg(arglst, unsigned int), flag);
	else if (ft_strequ(flag, "h"))
		res = ft_choosebase(s, (unsigned short)va_arg(arglst, int), flag);
	else
		res = ft_choosebase(s, va_arg(arglst, unsigned int), flag);
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
		res = ifddori(arglst, flag);
	else if (block->flag.spec == 'u' || block->flag.spec == 'o' ||
block->flag.spec == 'x' || block->flag.spec == 'X' || block->flag.spec == 'p')
		res = ifnotdori(arglst, flag, s);
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

char	*issorwchar(char *s, t_case *block, va_list arglst, char *flag)
{
	char *res;

	res = 0;
	if (ft_strequ(s, "S") || ft_strequ(s, "ls"))
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
	else if (!res)
		res = ft_findspectwo(block, arglst, flag, s);
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
	else
		res = issorwchar(s, block, arglst, flag);
	ft_strdel(&flag);
	ft_strdel(&s);
	return (res);
}

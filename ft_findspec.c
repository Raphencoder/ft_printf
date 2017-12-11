/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:58:19 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/11 21:21:55 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/*
**	This function will identify wich function to call depending on the
**  comparison between the 'str' passed in parameter and the string that i
**	will write.
** 	\\\\\\\---MANQUE C, S, P ET N----///////
*/

char	*ft_findspec(t_case *block, va_list arglst)
{
	char	*s;

	s = ft_grepspec(block->content);
	if (ft_strequ(s, "d") || ft_strequ(s, "i"))
		return (ft_itoa(va_arg(arglst, int)));
	else if (ft_strequ(s, "hhd") || ft_strequ(s, "hhi"))
		return (ft_itoasc(va_arg(arglst, signed char)));
	else if (ft_strequ(s, "hd") || ft_strequ(s, "hi"))
		return (ft_itoasi(va_arg(arglst, short int)));
	else if (ft_strequ(s, "ld") || ft_strequ(s, "li"))
		return (ft_itoali(va_arg(arglst, long int)));
	else if (ft_strequ(s, "lld") || ft_strequ(s, "lli"))
		return (ft_itoalli(va_arg(arglst, long long int)));
	else if (ft_strequ(s, "jd") || ft_strequ(s, "ji"))
		return (ft_itoait(va_arg(arglst, intmax_t)));
	else if (ft_strequ(s, "zd") || ft_strequ(s, "zi"))
		return (ft_itoast(va_arg(arglst, size_t)));
	else if (ft_strequ(s, "td") || ft_strequ(s, "ti"))
		return (ft_itoapt(va_arg(arglst, int /*ptrdiff_t */)));
	else if ((ft_strequ(s, "u") || ft_strequ(s, "o") || ft_strequ(s, "x") ||
ft_strequ(s, "X")))
		return (ft_unsigned_int());
	else if ((ft_strequ(s, "hhu") || ft_strequ(s, "hho") ||
ft_strequ(s, "hhx") || ft_strequ(s, "hhX")))
		return (ft_unsigned_char());
	else if ((ft_strequ(s, "hu") || ft_strequ(s, "ho") ||
ft_strequ(s, "hx") || ft_strequ(s, "hX")))
		return (ft_unsigned_short_int());
	else if ((ft_strequ(s, "lu") || ft_strequ(s, "lo") ||
ft_strequ(s, "lx") || ft_strequ(s, "lX")))
		return (ft_unsigned_long_int());
	else if ((ft_strequ(s, "llu") || ft_strequ(s, "llo") ||
ft_strequ(s, "llx") || ft_strequ(s, "llX")))
		return (ft_unsigned_long_long_int());
	else if ((ft_strequ(s, "ju") || ft_strequ(s, "jo") ||
ft_strequ(s, "jx") || ft_strequ(s, "jX")))
		return (ft_uintmax_t());
	else if ((ft_strequ(s, "zu") || ft_strequ(s, "zo") ||
ft_strequ(s, "zx") || ft_strequ(s, "zX")))
		return (ft_size_t());
	else if ((ft_strequ(s, "tu") || ft_strequ(s, "to") ||
ft_strequ(s, "tx") || ft_strequ(s, "tX")))
		return (ft_ptrdiff_t());
	else if ((ft_strequ(s, "f") || ft_strequ(s, "F") || ft_strequ(s, "e") ||
ft_strequ(s, "E") || ft_strequ(s, "g") || ft_strequ(s, "G") ||
ft_strequ(s, "a") || ft_strequ(s, "A")))
		return (ft_double());
	else if ((ft_strequ(s, "Lf") || ft_strequ(s, "LF") || ft_strequ(s, "Le") ||
ft_strequ(s, "LE") || ft_strequ(s, "Lg") || ft_strequ(s, "LG") ||
ft_strequ(s, "La") || ft_strequ(s, "LA")))
		return (ft_long_double());
	else if (ft_strequ(s, "c"))
		return (*s);
	else if (ft_strequ(s, "s"))
		return (*s);
	return (0);
}

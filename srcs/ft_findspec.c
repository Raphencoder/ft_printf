/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:58:19 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/22 11:39:08 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	This function will identify wich function to call depending on the
**  comparison between the 'str' passed in parameter and the string that i
**	will write.
*/

char	*ft_findspec(t_case *block, va_list arglst)
{
	char	*s;

	ft_putflags(block);
	s = ft_grepspec(block->content);
//	s = ft_strminimalize(block->content);
	if (block->flag.spec)
		block->flag.spec = ft_takespec(s);
	if (s == NULL)
		return (block->content);
	if (ft_strequ(s, "%"))
		return ("%");
	else if (ft_strequ(s, "d") || ft_strequ(s, "hhd") || ft_strequ(s, "i") || 
ft_strequ(s, "hhi") || ft_strequ(s, "hd") || ft_strequ(s, "hi") || ft_strequ(s, "ld") || ft_strequ(s, "li") || ft_strequ(s, "lld") || ft_strequ(s, "lli"))
		return (ft_itoabasetu("0123456789", va_arg(arglst, long long int)));
	else if ((ft_strequ(s, "o") || ft_strequ(s, "d") || ft_strequ(s, "i") || 
ft_strequ(s, "hhd") || ft_strequ(s, "hhi") || ft_strequ(s, "hd") || 
ft_strequ(s, "hi") || (ft_strequ(s, "ld") || ft_strequ(s, "li")) || 
ft_strequ(s, "lld") || ft_strequ(s, "lli") || ft_strequ(s, "jd") || 
ft_strequ(s, "ji") || ft_strequ(s, "zi") || ft_strequ(s, "td") || 
ft_strequ(s, "ti") || ft_strequ(s, "ho") || ft_strequ(s, "hho") || 
ft_strequ(s, "lo") || ft_strequ(s, "llo") || ft_strequ(s, "jo") || 
ft_strequ(s, "to") || ft_strequ(s, "zo") || ft_strequ(s, "u") || 
ft_strequ(s, "hu") || ft_strequ(s, "hhu") || ft_strequ(s, "lu") || 
ft_strequ(s, "llu") || ft_strequ(s, "ju") || ft_strequ(s, "tu") || 
ft_strequ(s, "zu") || ft_strequ(s, "zd") || ft_strequ(s, "x") || 
ft_strequ(s, "hx") || ft_strequ(s, "hhx") || ft_strequ(s, "lx") || 
ft_strequ(s, "llx") || ft_strequ(s, "jx") || ft_strequ(s, "tx") || 
ft_strequ(s, "zx") || ft_strequ(s, "X") || ft_strequ(s, "hX") || 
ft_strequ(s, "hhX") || ft_strequ(s, "lX") || ft_strequ(s, "llX") || 
ft_strequ(s, "jX") || ft_strequ(s, "tX") || ft_strequ(s, "zX") || 
ft_strequ(s, "b") || ft_strequ(s, "hb") || ft_strequ(s, "hhb") || 
ft_strequ(s, "lb") || ft_strequ(s, "llb") || ft_strequ(s, "jb") || 
ft_strequ(s, "tb") || ft_strequ(s, "zb") || ft_strequ(s, "p")))
			return (ft_choosebase(s, va_arg(arglst, uintmax_t)));
	else if (ft_strequ(s, "c") || (ft_strequ(s, "lc")))
			return (ft_intc(va_arg(arglst, int), block));
	else if (ft_strequ(s, "s") || ft_strequ(s, "ls"))
			return (va_arg(arglst, char*));
	ft_putstr(s);
	return (0);
}

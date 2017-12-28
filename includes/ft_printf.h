/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:09:41 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/21 18:41:45 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"

#include<stdlib.h>
# include <stddef.h>
#include <stdarg.h>

typedef	struct	s_flag
{
	int		spec;
	int		plus;
	int		less;
	int		space;
	int		dot;
	int		sharp;
	int		zero;
	int		width;

}				t_flag;

typedef	struct	s_case
{
	char			*content;
	size_t			content_size;
	struct s_flag	flag;
	struct s_case	*next;

}					t_case;

char		*ft_itoabasetu(char *str, long long int);
void		ft_newblck(char *str, int i, int len, t_case **start);
int			ft_printlst(t_case *start);
void		ft_mvinlst(t_case *block);
void		ft_putflags(t_case *block);
void    	ft_call(t_case *block, va_list arglst);
int			ft_isspec(char c);
int			ft_takespec(char *s);
int     	ft_isflag(char c);
int     	ft_ischar(char c);
int     	ft_issigned(char *str);
int     	ft_islength(char c);
char			*ft_deletechar(char *str, char c);
char		*ft_applyflag(t_case *block, char *str);
int     	ft_printf(char const * restrict format, ...);
char        *ft_itoast(size_t nbr);
char    	*ft_findspec(t_case *block, va_list arglst);
char		*ft_scs(int nb, char c);
char		*ft_choosebase(char *str, uintmax_t nb);
char    	*ft_grepspec(char *str);
char		*ft_intc(char c, t_case *block);
t_case      **ft_fillstr(char *format);
#endif

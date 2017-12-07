/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:09:41 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/07 16:43:22 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"

#include<stdlib.h>
#include <stdarg.h>

typedef	struct	s_flag
{
	int		plus;
	int		less;
	int		space;
	int		sharp;
	int		zero;

}				t_flag;

typedef	struct	s_case
{
	char			*content;
	size_t			content_size;
	struct s_flag	flag;
	struct s_case	*next;

}					t_case;

int     ft_printf(const char * restrict format, ...);
void	ft_newblck(char *str, int i, t_case **start);
void	ft_printlst(t_case *start);
int		ft_isspec(char c);
#endif

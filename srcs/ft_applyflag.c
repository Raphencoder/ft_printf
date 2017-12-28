/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:40:39 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/28 02:11:50 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"




char		*ft_applyflag(t_case *block, char *s)
{
	int sign;
	int hey;
	int i;
	char *tmp;

	hey = 0;
	sign = 0;
	if (block->flag.sharp && block->flag.zero && block->flag.width)
		block->flag.width -= 2;
	if (!block->flag.less && (block->flag.spec == 'd' || block->flag.spec == 'i'))
	{
		if (ft_strchr(s, '-'))
			sign = 1;
	}
	if (block->flag.dot == -1 && !ft_strcmp(s, "0") && !block->flag.sharp)
		s = ft_strdup("");

	else if (block->flag.dot == -1 && ft_strequ(s, "0"))
	{
		if (block->flag.sharp && block->flag.spec != 'o')
			s = ft_strdup("");
	}	
	if ((block->flag.plus) && block->flag.width && !sign)
		block->flag.width--;
	if (block->flag.spec != 's' && block->flag.spec != 'c')
	{
		if (block->flag.width && block->flag.dot)
		{
			if (block->flag.dot > block->flag.width)
				block->flag.less = 0;
		}
	}
	if (block->flag.sharp && (block->flag.spec == 'X' || block->flag.spec == 'x' || block->flag.spec == 'o') && block->flag.dot != -1 && ft_strcmp("0", s) && !block->flag.zero)
	{	
		if (block->flag.spec == 'X')
			s = ft_strjoin("0X", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0x", s);
		else if (block->flag.spec == 'o')
			s = ft_strjoin("0", s);
	}
	if (block->flag.dot)
	{
		if (block->flag.spec == 's' || block->flag.spec == 'c')
		{
			if (block->flag.dot < (int)ft_strlen(s))
				s = ft_strndup(s, block->flag.dot);
		}
		else
		{
			if (sign && block->flag.dot > (int)ft_strlen(s) - 1)
				s = ft_strjoin(ft_scs((block->flag.dot - ((int)ft_strlen(s) - 1)), '0'), s);
			else if (block->flag.dot > (int)ft_strlen(s))
				s = ft_strjoin(ft_scs((block->flag.dot - (int)ft_strlen(s)), '0'), s);
		}
		if (block->flag.zero && block->flag.width)
		{
			hey = 1;
			if (block->flag.width > block->flag.dot)
			{
				if (sign)
					s = ft_strjoin(ft_scs((block->flag.width - ((int)ft_strlen(s))), ' '), s);
				else 
					s = ft_strjoin(ft_scs((block->flag.width - (int)ft_strlen(s)), ' '), s);
			}
		}
	}
	if (block->flag.zero && block->flag.spec != 's' && block->flag.spec != 'c' && block->flag.dot == 0)
		s = ft_strjoin(ft_scs(block->flag.width - (int)ft_strlen(s), '0'), s);
	if (block->flag.less && !block->flag.zero)
		s = ft_strjoin(s, ft_scs(block->flag.width - (int)ft_strlen(s), ' ' ));
	else if (block->flag.width && !block->flag.zero)
	{
		if (block->flag.less)
			s = ft_strjoin(s, ft_scs(block->flag.width - (int)ft_strlen(s), ' ' ));
		else 
			s = ft_strjoin(ft_scs(block->flag.width - (int)ft_strlen(s), ' ' ), s);

	}
	if (block->flag.sharp && (block->flag.spec == 'X' || block->flag.spec == 'x' || block->flag.spec == 'o') && block->flag.dot != -1 && ft_strcmp("0", s) && block->flag.zero)
	{	
		if (block->flag.spec == 'X')
			s = ft_strjoin("0X", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0x", s);
		else if (block->flag.spec == 'x')
			s = ft_strjoin("0", s);
	}
	if (block->flag.space && (!block->flag.width && !block->flag.less) && !block->flag.plus && !sign)
		s = ft_strjoin(" ", s);
	if (sign && (block->flag.zero || block->flag.dot))
		s = ft_deletechar(s, '-');
	if (sign && (block->flag.zero || block->flag.dot))
	{
		//ici jai voulu mettre le moins colle au chiffre et pas au debut de le chaine, du coup jai avance
		//jusqua un espace puis jai cree un tmp qui va etre que des espace pour ensuite le join a la chaine initial
		if (block->flag.dot)
		   s = ft_strjoin("-", s);
		else
		{
			i = 0;
			while (s[i] <= 32 && s[i])
				i++;
			tmp = s;
			s = ft_strjoin("-", s + i);
			tmp = ft_strndup(tmp, i);
			s = ft_strjoin(tmp, s);
		}
	}
	if (block->flag.plus && !sign)
	{
		if (block->flag.width)
		{
			i = 0;
			while (s[i] <= 32 && s[i])
			i++;
			tmp = s;
			s = ft_strjoin("+", s + i);
			tmp = ft_strndup(tmp, i);
			s = ft_strjoin(tmp, s);
		}
		else 
			s = ft_strjoin("+", s);
	}
	return (s);
}

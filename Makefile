# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 15:37:08 by rkrief            #+#    #+#              #
#    Updated: 2017/12/20 00:29:29 by Raphael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		ft_printf.a

HEADER =	includes

P_SRC = 	ft_newblck.c \
			ft_printlst.c \
			ft_fillstr.c \
			ft_takespec.c \
			ft_deletechar.c \
			ft_findspec.c \
			ft_isspec.c \
			ft_mvinlst.c \
			ft_putflags.c \
			ft_isflag.c \
			ft_issigned.c \
			ft_islength.c \
			ft_ischar.c \
			ft_applyflag.c \
			ft_printf.c \
			ft_findspec.c \
			ft_choosebase.c \
			ft_grepspec.c \
			ft_intc.c \
			ft_scs.c \
			ft_call.c
			

P_OBJ =		ft_newblck.o \
			ft_fillstr.o \
			ft_ischar.o \
			ft_printlst.o \
			ft_deletechar.o \
			ft_takespec.o \
			ft_isspec.o \
			ft_findspec.o \
			ft_mvinlst.o \
			ft_putflags.o \
			ft_isflag.o \
			ft_issigned.o \
			ft_islength.o \
			ft_applyflag.o \
			ft_printf.o \
			ft_findspec.o \
			ft_choosebase.o \
			ft_grepspec.o \
			ft_intc.o \
			ft_scs.o \
			ft_call.o
			

L_SRC =		./libft/ft_putchar.c \
			./libft/ft_putstr.c \
			./libft/ft_memset.c \
			./libft/ft_bzero.c \
			./libft/ft_memcpy.c \
			./libft/ft_memccpy.c \
			./libft/ft_memmove.c \
			./libft/ft_memchr.c \
			./libft/ft_memcmp.c \
			./libft/ft_strlen.c \
			./libft/ft_strdup.c \
			./libft/ft_strcpy.c \
			./libft/ft_strncpy.c \
			./libft/ft_strcat.c \
			./libft/ft_strncat.c \
			./libft/ft_strlcat.c \
			./libft/ft_strchr.c \
			./libft/ft_strrchr.c \
			./libft/ft_itoa.c \
			./libft/ft_strstr.c \
			./libft/ft_strnstr.c \
			./libft/ft_strcmp.c \
			./libft/ft_strncmp.c \
			./libft/ft_isalpha.c \
			./libft/ft_isdigit.c \
			./libft/ft_isalnum.c \
			./libft/ft_isascii.c \
			./libft/ft_isprint.c \
			./libft/ft_toupper.c \
			./libft/ft_tolower.c \
			./libft/ft_atoi.c \
			./libft/ft_memalloc.c \
			./libft/ft_strmap.c \
			./libft/ft_strmapi.c \
			./libft/ft_memdel.c \
			./libft/ft_strnew.c \
			./libft/ft_strdel.c \
			./libft/ft_strclr.c \
			./libft/ft_striter.c \
			./libft/ft_striteri.c \
			./libft/ft_strequ.c \
			./libft/ft_strnequ.c \
			./libft/ft_strsplit.c \
			./libft/ft_strsub.c \
			./libft/ft_putnbr.c \
			./libft/ft_strjoin.c \
			./libft/ft_strtrim.c \
			./libft/ft_putendl.c \
			./libft/ft_putchar_fd.c \
			./libft/ft_putstr_fd.c \
			./libft/ft_putendl_fd.c \
			./libft/ft_putnbr_fd.c \
			./libft/ft_lstnew.c \
			./libft/ft_lstdelone.c \
			./libft/ft_lstdel.c \
			./libft/ft_lstadd.c \
			./libft/ft_lstiter.c \
			./libft/ft_strminimalize.c \
			./libft/ft_lstmap.c \
			./libft/ft_strndup.c



L_OBJ =		ft_putchar.o \
			ft_putstr.o \
			ft_memset.o \
			ft_bzero.o \
			ft_memcpy.o \
			ft_memccpy.o \
			ft_memmove.o \
			ft_memchr.o \
			ft_memcmp.o \
			ft_strlen.o \
			ft_strdup.o \
			ft_strcpy.o \
			ft_strncpy.o \
			ft_strcat.o \
			ft_strncat.o \
			ft_strlcat.o \
			ft_strchr.o \
			ft_strrchr.o \
			ft_itoa.o \
			ft_strstr.o \
			ft_strnstr.o \
			ft_strcmp.o \
			ft_strncmp.o \
			ft_isalpha.o \
			ft_strminimalize.o \
			ft_isdigit.o \
			ft_isalnum.o \
			ft_isascii.o \
			ft_isprint.o \
			ft_toupper.o \
			ft_tolower.o \
			ft_atoi.o \
			ft_memalloc.o \
			ft_strmap.o \
			ft_strmapi.o \
			ft_memdel.o \
		 	ft_strnew.o \
			ft_strdel.o \
			ft_strclr.o \
			ft_striter.o \
			ft_striteri.o \
			ft_strequ.o \
			ft_strnequ.o \
			ft_strsplit.o \
			ft_strsub.o \
			ft_putnbr.o \
			ft_strjoin.o \
			ft_strtrim.o \
			ft_putendl.o \
			ft_putchar_fd.o \
			ft_putstr_fd.o \
			ft_putendl_fd.o \
			ft_putnbr_fd.o \
			ft_lstnew.o \
			ft_lstdelone.o \
			ft_lstdel.o \
			ft_lstadd.o \
			ft_lstiter.o \
			ft_lstmap.o \
			ft_strndup.o

FLAG =		 -Wall -Werror -Wextra -g

all :		$(NAME)

$(NAME) :	
			@gcc -c -I$(HEADER) $(FLAG) $(P_SRC) $(L_SRC)
			@ar rc $(NAME) $(L_OBJ) $(P_OBJ)

clean :
			@rm -rf $(L_OBJ) $(P_OBJ)

run :		re
	@make clean

fclean :	clean
			@rm -rf $(NAME)

re :		fclean all

.PHONY : clean all re run fclean

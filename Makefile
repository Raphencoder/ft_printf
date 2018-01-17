# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 15:37:08 by rkrief            #+#    #+#              #
#    Updated: 2018/01/17 13:10:34 by briviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

HEADER =	includes

SRC =		srcs

P_SRC = 	ft_newblck.c \
			ft_minimalize.c \
			ft_itoap.c \
			ft_applybegin.c \
			applyflagtwo.c \
			ft_applyflagthree.c \
			ft_printlst.c \
			ft_fillstr.c \
			ft_takespec.c \
			ft_putwstr.c \
			ft_deletechar.c \
			ft_findspec.c \
			ft_putspacetwo.c \
			ft_isspec.c \
			ft_itoac.c \
			ft_takeflag.c \
			ft_mvinlst.c \
			ft_putflags.c \
			ifdot.c \
			ft_isflag.c \
			ft_issigned.c \
			ft_islength.c \
			ft_putspace.c \
			ft_ischar.c \
			ft_applyflag.c \
			ft_printf.c \
			ft_findspec.c \
			ft_choosebase.c \
			ft_grepspec.c \
			ft_intc.c \
			ft_scs.c \
			ft_call.c \

SRCS = $(addprefix $(SRC)/, $(P_SRC))

L_SRC =		libft/ft_putchar.c \
			libft/ft_putwchar.c \
			libft/ft_putstr.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_memcpy.c \
			libft/ft_memccpy.c \
			libft/ft_memmove.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strlen.c \
			libft/ft_strdup.c \
			libft/ft_strcpy.c \
			libft/ft_strncpy.c \
			libft/ft_strcat.c \
			libft/ft_strncat.c \
			libft/ft_strlcat.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_itoa.c \
			libft/ft_strstr.c \
			libft/ft_strnstr.c \
			libft/ft_strcmp.c \
			libft/ft_strncmp.c \
			libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_isascii.c \
			libft/ft_isprint.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_atoi.c \
			libft/ft_memalloc.c \
			libft/ft_strmap.c \
			libft/ft_strmapi.c \
			libft/ft_memdel.c \
			libft/ft_strnew.c \
			libft/ft_strdel.c \
			libft/ft_strclr.c \
			libft/ft_striter.c \
			libft/ft_striteri.c \
			libft/ft_strequ.c \
			libft/ft_strnequ.c \
			libft/ft_strsplit.c \
			libft/ft_strsub.c \
			libft/ft_putnbr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_putendl.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew.c \
			libft/ft_lstdelone.c \
			libft/ft_lstdel.c \
			libft/ft_lstadd.c \
			libft/ft_lstiter.c \
			libft/ft_strminimalize.c \
			libft/ft_lstmap.c \
			libft/ft_strndup.c



OBJ =		$(patsubst libft/%.c, libft/%.o, $(L_SRC))\
			$(patsubst $(SRC)/%.c, $(SRC)/%.o, $(SRCS))

FLAG =		 -Wall -Werror -Wextra -g

all :		$(NAME)

$(NAME) :	$(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc -c -I$(HEADER) $(FLAG) $< -o $@

clean :
	@rm -rf $(OBJ) $(OBJ)

run :		re
	@make clean

fclean :	clean
	@rm -rf $(NAME)

re :		fclean all

.PHONY : clean all re run fclean

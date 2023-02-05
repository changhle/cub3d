# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhle <changhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 21:21:34 by changhle          #+#    #+#              #
#    Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar
ARFLAGS		=	-crs
RM			=	rm -f

NAME		=	libft.a

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_atoi.c ft_memcmp.c ft_bzero.c ft_memset.c \
				ft_memchr.c ft_memcpy.c ft_memmove.c ft_strncmp.c \
				ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strnstr.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				ft_iseq.c ft_malloc.c ft_free.c ft_close.c \
				get_next_line.c get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

%.o			:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re

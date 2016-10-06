# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalexand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 11:33:52 by dalexand          #+#    #+#              #
#*   Updated: 2016/02/27 14:23:21 by dalexand         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_itoa.c ft_memccpy.c ft_putchar.c ft_putstr_fd.c \
	ft_strdup.c ft_strmap.c ft_strnstr.c ft_toupper.c \
	ft_bzero.c ft_lstdel.c ft_memchr.c ft_putchar_fd.c \
	ft_strcat.c ft_strequ.c ft_strmapi.c ft_strrchr.c ft_lstadd.c \
	ft_isalnum.c ft_lstdelone.c ft_memcmp.c ft_putendl.c \
	ft_strchr.c ft_striter.c ft_strncat.c ft_strsplit.c \
	ft_isalpha.c ft_lstiter.c ft_memcpy.c ft_putendl_fd.c \
	ft_strclr.c ft_striteri.c ft_strncmp.c ft_strstr.c \
	ft_isascii.c ft_lstmap.c ft_memdel.c ft_putnbr.c \
	ft_strcmp.c ft_strjoin.c ft_strncpy.c ft_strsub.c \
	ft_isdigit.c ft_lstnew.c ft_memmove.c ft_putnbr_fd.c \
	ft_strcpy.c ft_strlcat.c ft_strnequ.c ft_strtrim.c \
	ft_isprint.c ft_memalloc.c ft_memset.c ft_putstr.c \
	ft_strdel.c ft_strlen.c ft_strnew.c ft_tolower.c \
	ft_iswhitespace.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $<

$(NAME): $(OBJ)
	ar rc libft.a $(OBJ)
	ranlib libft.a

clean:
	rm -f $(OBJ)

fclean:
	rm -f libft.a

re: fclean clean all

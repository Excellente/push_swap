# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsimang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/13 14:17:32 by emsimang          #+#    #+#              #
#    Updated: 2016/11/22 11:58:02 by emsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	 = gcc
CFLAGS	 = -c -Wall -Wextra -Werror
NAME     = libft.a

SRC	 = ft_atoi.c\
	   ft_putnbr_fd.c\
	   ft_putstr_fd.c\
	   ft_putchar_fd.c\
	   ft_strsplit.c\
	   ft_strtrim.c\
	   ft_strslen.c\
	   ft_bzero.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_islower.c\
	   ft_isprint.c\
	   ft_isupper.c\
	   ft_iswhitespace.c\
	   ft_itoa.c\
	   ft_memcpy.c\
	   ft_memchr.c\
	   ft_memccpy.c\
	   ft_memdel.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_power.c\
	   ft_putchar.c\
	   ft_putnbr.c\
	   ft_putstr.c\
	   ft_strcat.c\
	   ft_strchr.c\
	   ft_memalloc.c\
	   ft_strclr.c\
	   ft_strcmp.c\
	   ft_strcpy.c\
	   ft_strdel.c\
	   ft_strdup.c\
	   ft_strequ.c\
	   ft_striter.c\
	   ft_strjoin.c\
	   ft_strlcat.c\
	   ft_strlen.c\
	   ft_strncat.c\
	   ft_strncmp.c\
	   ft_strncpy.c\
	   ft_strnew.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strsub.c\
	   ft_tolower.c\
	   ft_toupper.c\

INC = ./include/
SRCDIR = ./src/
OBJDIR = ./objs/

OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(OBJ))

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -I$(INC)
	mv $(OBJ) $(OBJDIR)
	ar rc  $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

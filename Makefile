# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsimang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/23 16:21:43 by emsimang          #+#    #+#              #
#    Updated: 2016/11/21 17:14:25 by emsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker
PUSH = push_swap
NAME = libsort.a
CC = gcc
CFLAG = -c
WFLAGS = #-Wall -Werror -Wextra
SRC = error.c sub_ops_a.c push_swap.c validate_arg.c checker.c \
	  operations.c sort_seque.c stack_man.c stack_init.c conditions.c \

LIBFT = libft/libft.a
OBJ	= $(SRC:.c=.o)
SRCDIR	= ./src/
OBJDIR	= ./objs/
INCDIR	= ./includes/
FTOBJS  = $(addprefix $(FT_OBJDIR), $(FT_OBJ))
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME) $(PUSH) $(CHECK)

$(NAME) :
	cd libft && make && cd ..
	$(CC) $(CFLAG) $(WFLAGS) -I$(INCDIR) $(SRCS)
	mv $(OBJ) $(OBJDIR)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	clear

$(PUSH):
	$(CC) $(WFLAGS) ./objs/push_swap.o -I$(INCDIR) $(NAME) $(LIBFT) -o $(PUSH)

$(CHECK):
	$(CC) $(CFLAGS) ./objs/checker.o $(NAME) -I $(INCDIR) $(LIBFT) -o $(CHECK)

clean:
	rm -rf $(OBJS)
	cd libft && make clean && cd ..

fclean: clean
	rm -f $(NAME)
	rm -f $(PUSH)
	rm -f $(CHECK)
	cd libft && make fclean && cd ..

re: fclean all

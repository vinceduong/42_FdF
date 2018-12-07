# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 21:40:25 by vduong            #+#    #+#              #
#    Updated: 2018/12/07 22:38:30 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = gcc $(FLAGS) $(INCLUDES)

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./minilbx -I./libft/includes -I./files/includes

NAME = fdf

SRCS = files/sources/main.c\
		files/sources/error.c\
		files/sources/init.c\

LIBFT = libft/libft.a

MINILBX = minilbx/libmlx.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT) : 
	make -C libft
$(MINILBX) : 
	make -C minilbx

$(NAME) : $(OBJS) $(LIBFT) $(MINILBX)
	$(CC) $(OBJS) $(LIBFT) $(MINILBX) -o $(NAME)

clean :
	rm -rf $(OBJS)
	make clean -C libft
	make clean -C minilbx

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(MINILBX)

re : fclean all

up : all clean
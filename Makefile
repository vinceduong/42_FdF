# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 21:40:25 by vduong            #+#    #+#              #
#    Updated: 2018/12/08 09:54:12 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = gcc $(FLAGS) $(INCLUDES)

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lminilbx/ -framework OpenGL -framework AppKit 

INCLUDES = -I./minilbx -I./libft -I./files/includes

NAME = fdf

SRCS = files/sources/main.c\
		files/sources/error.c\
		files/sources/init.c\
		files/sources/parse.c\

LIBFT = libft/libft.a

MINILBX = minilbx/libmlx.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT) : 
	make -C libft

$(MINILBX) : 
	make -C minilbx

$(NAME) : $(OBJS) $(LIBFT) $(MINILBX)
	$(CC) $(OBJS) $(LIBFT) $(MINILBX) $(MLX_FLAGS) -o $(NAME)

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
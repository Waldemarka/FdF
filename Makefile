# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 15:11:47 by vomelchu          #+#    #+#              #
#    Updated: 2018/06/08 15:11:50 by vomelchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAG = -Wall -Werror -Wextra

SRC = fdf.c other.c bresenham.c draw.c \
	get_next_line.c itoa_base.c forkey.c 

INCLUDE = ./includes

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
	make -C ./libft/
	$(CC) $(FLAG) -I$(INCLUDE) $(SRC) -lmlx -framework OpenGL -framework Appkit ./libft/libft.a -o $(NAME)
	# ar rc $(NAME) $(SRO)

%.o: %.c ./includes/fdf.h
	$(CC) $(FLAG) -c -Wextra -Wall -Werror -o $@ $<

clean:
	make -C libft/ clean
	rm -f $(SRO)

fclean: clean
	make -C libft/ fclean
	rm -Rf $(NAME)

re: fclean all
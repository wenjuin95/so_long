# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 13:38:29 by welow             #+#    #+#              #
#    Updated: 2024/02/05 23:01:40 by welow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRC = src/so_long.c

INC = src/

OBJ_SRC = $(SRC:.c=.o)

# MINILIBX_LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX_LIBRARY = -Lminilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# MINILIBX = minilibx/
MINILIBX = minilibx-linux/

all: $(NAME)

$(NAME) : $(OBJ_SRC)
	make -C $(MINILIBX)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(SRC) libft.a $(MINILIBX_LIBRARY) -I$(INC) -o $(NAME)

%.o: %.C
	$(CC) $(CFLAG) -c $< -o $@

clean:
	make clean -C libft
	make clean -C $(MINILIBX)
	rm -f $(OBJ_SRC)
	rm -f libft.a

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	
re : fclean all

.PHONY : all clean fclean re 
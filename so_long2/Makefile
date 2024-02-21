# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welow <welow@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 13:38:29 by welow             #+#    #+#              #
#    Updated: 2024/02/21 16:07:18 by welow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/so_long.c src/get_image.c src/error_handling.c src/read_map.c src/init.c \
	  src/control_1.c src/control_2.c src/gameplay.c src/animation.c src/enermy.c

OBJ_DIR = temp_obj
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

ifeq ($(shell uname), Linux)
	MINILIBX = minilibx-linux/
else
	MINILIBX = minilibx/
endif

ifeq ($(shell uname), Linux)
	MINILIBX_LIBRARY = -Lminilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MINILIBX_LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
endif

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ_SRC)
	make -C $(MINILIBX)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_SRC) libft.a $(MINILIBX_LIBRARY) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C $(MINILIBX)
	rm -rf $(OBJ_DIR)
	rm -f libft.a

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	
re : fclean all

.PHONY : all clean fclean re 
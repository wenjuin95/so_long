# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 13:38:29 by welow             #+#    #+#              #
#    Updated: 2024/02/07 20:50:39 by welow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/so_long.c src/get_image.c src/error_handling.c src/read_map.c src/animation.c src/check_input.c

OBJ_DIR = temp_obj
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# MINILIBX_LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX_LIBRARY = -Lminilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# MINILIBX = minilibx/
MINILIBX = minilibx-linux/

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
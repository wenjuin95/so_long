# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welow <welow@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 13:38:29 by welow             #+#    #+#              #
#    Updated: 2024/03/08 15:30:13 by welow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC = src/so_long.c src/get_image.c src/error_handling.c src/read_map.c src/init.c \
	  src/control_1.c src/control_2.c src/gameplay.c

BONUS = bonus/so_long_bonus.c bonus/get_image_bonus.c bonus/error_handling_bonus.c bonus/read_map_bonus.c bonus/init_bonus.c \
	  bonus/control_1_bonus.c bonus/control_2_bonus.c bonus/gameplay_bonus.c bonus/animation_bonus.c bonus/enermy_bonus.c

OBJ_SRC = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

ifeq ($(shell uname), Linux)
	MINILIBX = minilibx-linux/
	MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MINILIBX = minilibx/
	MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit
endif

all: $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ_SRC)
	make -C $(MINILIBX)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_SRC) libft.a $(MINILIBX_LIBRARY) -o $(NAME)

bonus: $(OBJ_BONUS)
	make -C $(MINILIBX)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_BONUS) libft.a $(MINILIBX_LIBRARY) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C $(MINILIBX)
	rm -rf $(OBJ_SRC)
	rm -rf $(OBJ_BONUS)
	rm -f libft.a

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	
re : fclean all

.PHONY : all clean fclean re bonus
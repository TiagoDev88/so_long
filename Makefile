#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 13:05:44 by tfilipe-          #+#    #+#              #
#    Updated: 2025/05/23 23:31:41 by tfilipe-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = so_long

CC = cc
CFLAGS =  -Wall -Wextra -Werror \
               -I includes \
               -I libft \
               -I minilibx-linux

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC_DIR = src
SRCS = src/main.c src/map_utils.c src/map.c src/player.c src/render.c src/utils.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm 

RM = rm -f

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "✅  $(NAME) compilado com sucesso!"

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)
	@echo "clean: object files removed"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "fclean: executable removed"

re: fclean all

.PHONY: all clean fclean re

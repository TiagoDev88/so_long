# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 13:05:44 by tfilipe-          #+#    #+#              #
#    Updated: 2025/05/29 14:13:24 by tfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

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
SRCS = src/main.c src/map_utils.c src/map.c src/player.c src/render.c src/utils.c src/check_map_path.c

SRC_DIR_BONUS = src_bonus
SRCS_BONUS = src_bonus/main_bonus.c src_bonus/map_utils_bonus.c src_bonus/map_bonus.c \
			src_bonus/player_bonus.c src_bonus/render_bonus.c src_bonus/utils_bonus.c \
			src_bonus/check_map_path_bonus.c src_bonus/player_move_bonus.c
			
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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
	@echo "✅  $(NAME) Compiled successfully!"

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	@echo "clean: object files removed"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "fclean: executable removed"

bonus: $(MLX) $(LIBFT) $(NAME_BONUS)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(SRC_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "✅  $(NAME_BONUS) Compiled successfully with bonus!"

re: fclean all

.PHONY: all clean fclean re

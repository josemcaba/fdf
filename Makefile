# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 01:47:42 by jocaball          #+#    #+#              #
#    Updated: 2023/08/07 17:18:26 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PNAME = fdf
SRC  = 	fdf.c read_map1.c read_map2.c translate.c perspectives.c plot.c \
		views.c hooks.c colors.c menu.c rotations.c
INC  = fdf.h

LIBFT      = ./libft/libft.a
MAKE_LIBFT = @make -sC ./libft

MLX42      = ./MLX42/libmlx42.a
MAKE_MLX42 = @make -sC ./MLX42

USER = $(shell whoami)
GLFW = -lm -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast

all : $(PNAME) 

$(NAME): 
	$(LIBFT) $(MLX42) $(PNAME)

$(LIBFT): 
	$(MAKE_LIBFT)

$(MLX42): 
	$(MAKE_MLX42)

$(PNAME): $(LIBFT) $(MLX42) $(SRC) $(INC)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MLX42) $(GLFW) -o $(PNAME)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(PNAME)$(GREEN) has been created\n$(DEF_COLOR)"

bonus: $(NAME)

clean :
	$(MAKE_LIBFT) clean 
	$(MAKE_MLX42) fclean

fclean : clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean
	$(MAKE_MLX42) fclean

re : fclean all

test: all
	leaks -atExit -- ./fdf test_maps/42.fdf

.PHONY: all bonus clean fclean re

DEF_COLOR = \033[0;39m
BLACK	  =	\033[0;30m
RED		  =	\033[1;91m
GREEN	  =	\033[1;92m
YELLOW	  = \033[0;93m
BLUE	  = \033[0;94m
MAGENTA	  = \033[0;95m
CYAN	  = \033[0;96m
GRAY	  = \033[0;90m
WHITE	  = \033[0;97m
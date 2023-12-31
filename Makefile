# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 01:47:42 by jocaball          #+#    #+#              #
#    Updated: 2023/08/24 19:12:45 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PNAME = fdf
SRC  = 	fdf.c read_map.c fill_points.c plot.c colors.c open_window.c hooks.c 
INC  = fdf.h

PNAME_B = fdf_bonus
SRC_B  = fdf_bonus.c read_map.c fill_points.c plot.c colors.c open_window.c   \
		 views_bonus.c hooks_bonus.c mouse_bonus.c achievement_bonus.c menu_bonus.c 
INC_B  = fdf_bonus.h

LIBFT      = ./libft/libft.a
MAKE_LIBFT = @make -sC ./libft

MLX42      = ./MLX42/libmlx42.a
MAKE_MLX42 = @make -sC ./MLX42

USER = $(shell whoami)
GLFW = -lm -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast

all : makelibs $(PNAME)

$(NAME):
	$(LIBFT) $(MLX42) $(PNAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(MLX42):
	$(MAKE_MLX42)

$(PNAME): $(LIBFT) $(MLX42) $(SRC) $(INC)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MLX42) $(GLFW) -o $(PNAME)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(PNAME)$(GREEN) has been created\n$(DEF_COLOR)"

bonus: makelibs $(PNAME_B)

$(NAME_B):
	$(LIBFT) $(MLX42) $(PNAME_B)

$(PNAME_B): $(LIBFT) $(MLX42) $(SRC_B) $(INC_B)
	@$(CC) -DBONUS $(CFLAGS) $(SRC_B) $(LIBFT) $(MLX42) $(GLFW) -o $(PNAME_B)
	@cp fdf_bonus fdf
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(PNAME) bonus$(GREEN) has been created\n$(DEF_COLOR)"

makelibs :
	$(MAKE_LIBFT)
	$(MAKE_MLX42)
	
clean :
	$(MAKE_LIBFT) clean 
	$(MAKE_MLX42) clean

fclean : clean
	@rm -f $(PNAME) $(PNAME_B) 
	$(MAKE_LIBFT) fclean
	$(MAKE_MLX42) fclean

re : fclean all

.PHONY: all bonus clean fclean re makelibs norma test

norma:
	norminette *.c *.h libft/*.c libft/*.h | grep Error

test: all
	leaks --atExit -- ./fdf "/Users/$(USER)/Documents/42cursus/fdf/test_maps/42subject.fdf"

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 05:34:22 by abiri             #+#    #+#              #
#    Updated: 2019/12/19 05:34:27 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_lCYAN = \x1b[96m
_lYELLOW = \x1b[93m
_lGREEN = \x1b[92m
_lBLUE = \x1b[94m
_RED = \x1b[31m
_BOLD = \x1b[1m
_END = \x1b[0m

CC = gcc

NAME = editor

FILENAMES = /main.c

HEADER_FILE = ./inc/editor.h

SRC_DIR = ./src

OBJ_DIR = ./obj

INC_DIR = ./inc

SRC = $(addprefix $(SRC_DIR), $(FILENAMES))

OBJ = $(addprefix $(OBJ_DIR), $(FILENAMES:.c=.o))

FLAGS = -Wall -Werror -Wextra

LIBFT = ../libs/centropy/centropy.a

LIBFT_DIR = ../libs/centropy

FT_SIMPLESDL = ../libs/FT_SimpleSDL/libftsimplesdl.a

FT_SIMPLESDL_DIR = ../libs/FT_SimpleSDL

INCLUDES = -I ../libs/centropy\
		   -I ./inc\
		   -I ../libs/FT_SimpleSDL/inc\
		   -I ~/.brew/Cellar/sdl2/2.0.9_1/include/SDL2\
		   -I ~/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2

LIBRARIES = -L ./libs/libft	-lft\
			-L ./libs/libft/ft_printf -lftprintf\
			-L ./libs/FT_SimpleSDL -lftsimplesdl\
			-L ~/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2\
			-L ~/.brew/Cellar/sdl2_ttf/2.0.15/lib -lSDL2_ttf

DELAY = 0

all : $(NAME)
$(NAME): $(LIBFT) $(FT_SIMPLESDL) $(FT_GRAPHICS) $(OBJ)
	@echo "$(CC) $(_lYELLOW)$(FLAGS)$(_END) $(_lCYAN)$(OBJ)$(_END)\n$(_lGREEN)$(LIBRARIES)$(_END) -I$(_RED)$(INC_DIR)$(_END)$(_RED)$(INCLUDES)$(_END) -o $(_lBLUE)$(NAME)$(_lEND)$(_RED)\n"
	@$(CC) $(FLAGS) $(OBJ) $(LIBRARIES) $(INCLUDES) -o $(NAME)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER_FILE) | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) $(INCLUDES)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_SIMPLESDL):
	@make -C $(FT_SIMPLESDL_DIR)

clean:
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(OBJ) $(VIS_OBJ)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_SIMPLESDL_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(NAME)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_SIMPLESDL_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 20:38:11 by abiri             #+#    #+#              #
#    Updated: 2019/12/19 05:46:41 by abiri            ###   ########.fr        #
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
AR = ar rc
NAME = libftsimplesdl.a
FILENAMES = init.c\
			init2.c\
			linked_lists.c\
			loop.c\
			draw.c\
			images.c\
			olddraw.c\
			loop2.c\
			ft_strdup.c\
			ft_memalloc.c
HEADER_FILE = ft_simplesdl.h\
			  SDL2.h
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC = $(addprefix $(SRC_DIR)/, $(FILENAMES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILENAMES:.c=.o))
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I $(INC_DIR)\
		   -I ~/.brew/Cellar/sdl2/2.0.9_1/include/SDL2
LIBRARIES = -L ~/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2
all : $(NAME)
$(NAME): $(OBJ)
	@echo "";
	@echo "╔═╗╔╦╗   ╔═╗┬┌┬┐┌─┐┬  ┌─┐    ╔═╗┌┬┐┬  ";
	@echo "╠╣  ║    ╚═╗││││├─┘│  ├┤     ╚═╗ │││  ";
	@echo "╚   ╩────╚═╝┴┴ ┴┴  ┴─┘└─┘────╚═╝─┴┘┴─┘";
	@echo "";
	@echo "$(AR) $(_lBLUE)$(NAME)$(_END) $(_lCYAN)$(OBJ)$(_END)"
	@$(AR) $(NAME) $(OBJ)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@echo "$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(OBJ) $(VIS_OBJ)$(_END)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(NAME)$(_END)"
	@rm -f $(NAME)

re: fclean all

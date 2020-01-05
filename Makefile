# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merras <merras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 17:30:55 by abiri             #+#    #+#              #
#    Updated: 2020/01/04 17:53:49 by merras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = doom_nukem
INC_DIR = ./includes
SRC_DIR = ./sources
LIBS_DIR = ./libraries
OBJ_DIR = ./objects
EDITOR_DIR = ./editor
SOURCE_FILES = game_loop/init_ui.c\
			   main.c\
			   shared_tools/display_events.c\
			   shared_tools/image_manipulations.c
HEADER_FILES = doom_nukem.h
SDL_VERSION = 2.0.10
SDL_TTF_VERSION = 2.0.15

# this part is automatic

SOURCES = $(addprefix $(SRC_DIR)/, $(SOURCE_FILES))
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCE_FILES:.c=.o))
INCLUDES = $(addprefix $(INC_DIR)/, $(HEADER_FILES))
LINKS = $(SIMPLESDL_LINK) $(CENTROPY_LINK) $(TTSLIST_LINK) $(SDL_LINK)
INCS = -I $(INC_DIR) $(SIMPLESDL_INC) $(CENTROPY_INC) $(TTSLIST_INC) $(SDL_INC)
OBJECT_DIRS = $(sort $(dir $(OBJECTS)))

.PHONY: all
all: $(NAME) editor

include $(LIBS_DIR)/library_linking.mk
include $(EDITOR_DIR)/editor_rules.mk

$(NAME): $(SIMPLESDL_NAME) $(CENTROPY_NAME) $(TTSLIST_NAME) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LINKS) -o $(NAME)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES) | $(OBJECT_DIRS)
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(OBJECT_DIRS):
	@-mkdir $(OBJECT_DIRS)

.PHONY: clean
clean: editor_clean simplesdl_clean centropy_clean ttslist_clean
	@-rm -rf $(OBJ_DIR)
	@-rm -rf $(EDITOR_OBJ_DIR)

.PHONY: fclean
fclean: clean editor_fclean simplesdl_fclean centropy_fclean ttslist_fclean
	@-rm -rf $(NAME)
	@-rm -rf $(EDITOR_NAME)

.PHONY: re
re: fclean all

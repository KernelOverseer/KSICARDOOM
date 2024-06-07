# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 17:30:55 by abiri             #+#    #+#              #
#    Updated: 2024/06/07 15:31:32 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -g -Ofast -std=gnu11
LMATH = -lm
ifeq ($(shell uname -s), Darwin)
	LMATH := -headerpad_max_install_names
endif
NAME = doom_nukem
INC_DIR = ./includes
SRC_DIR = ./sources
LIBS_DIR = ./libraries
OBJ_DIR = ./objects
EDITOR_DIR = ./editor
SOURCE_FILES = game_loop/init_ui.c\
			   graphical_engine/graphical_init.c\
			   graphical_engine/graphical_main.c\
			   graphical_engine/intersect_ray.c\
			   graphical_engine/object_constructors.c\
			   graphical_engine/raycast.c\
			   graphical_engine/temp_graphical_render.c\
			   graphical_engine/wall_drawing.c\
			   graphical_engine/portal_drawing.c\
			   graphical_engine/sprite_drawing.c\
			   graphical_engine/skybox.c\
			   graphical_engine/color_manipulations.c\
			   main.c\
			   physics/ft_physics_controllers.c\
			   physics/init_phi.c\
			   physics/velocity.c\
			   physics/force.c\
			   physics/gravity.c\
			   physics/collision.c\
			   players/ft_players.c\
			   players/ft_bots.c\
			   players/bot_template.c\
			   players/bot_tools.c\
			   players/ft_projectile.c\
			   players/ft_collectible.c\
			   shared_tools/time.c\
			   shared_tools/display_events.c\
			   shared_tools/error_management.c\
			   shared_tools/image_manipulations.c\
			   shared_tools/intersections.c\
			   shared_tools/keys.c\
			   shared_tools/garbage_collector.c\
			   serialization/load_map_data.c\
			   serialization/basic_type_serializer.c\
			   serialization/custom_editor_serializer.c\
			   serialization/load_map.c\
			   user_interface/main_menu.c\
			   user_interface/menu_management.c\
			   user_interface/menu_buttons.c\
			   user_interface/custom_menu_1.c\
			   user_interface/custom_menu_2.c\
			   user_interface/menu_load_helpers.c\
			   user_interface/hud_main.c\
			   user_interface/messages.c\
			   sound_engine/init.c\
			   networking/init.c\
			   networking/doom_init.c\
			   networking/scene_sync.c\
			   networking/body_sync.c\
			   players/ft_server_player.c\
			   players/ft_client_player.c

HEADER_FILES = animation_textures.h\
			   config.h\
			   doom_nukem.h\
			   error_management.h\
			   graphical_engine.h\
			   graphical_objects.h\
			   graphical_renderer.h\
			   graphics_drawing.h\
			   graphics_structs.h\
			   physics_engine.h\
			   ray_calculations.h\
			   raycasting.h\
			   scene_parser.h\
			   user_interface.h\
			   bots.h\
			   sound_engine.h\
			   networking.h

SDL_VERSION = 2.0.10
SDL_TTF_VERSION = 2.0.15

# this part is automatic

SOURCES = $(addprefix $(SRC_DIR)/, $(SOURCE_FILES))
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCE_FILES:.c=.o))
INCLUDES = $(addprefix $(INC_DIR)/, $(HEADER_FILES))
LINKS = $(SIMPLESDL_LINK) $(CENTROPY_LINK) $(TTSLIST_LINK) $(LIBGL_LINK) $(SDL_LINK) $(LMATH)
INCS = -I $(INC_DIR) $(SIMPLESDL_INC) $(CENTROPY_INC) $(TTSLIST_INC) $(LIBGL_INC) $(SDL_INC)
OBJECT_DIRS = $(sort $(dir $(OBJECTS)))

.PHONY: all
all: $(NAME) editor

include $(LIBS_DIR)/library_linking.mk
include $(EDITOR_DIR)/editor_rules.mk

INCS := $(INCS) $(EDITOR_INCLUDES)

$(NAME): $(SIMPLESDL_NAME) $(CENTROPY_NAME) $(TTSLIST_NAME) $(LIBGL_NAME) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LINKS) -o $(NAME)
ifeq ($(shell uname -s), Darwin)
	@-install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 @loader_path/$(SDL2) $(NAME)
	@-install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image @loader_path/$(SDL2_IMAGE) $(NAME)
	@-install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf @loader_path/$(SDL2_TTF) $(NAME)
	@-install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer @loader_path/$(SDL2_MIXER) $(NAME)
endif

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES) | $(OBJECT_DIRS)
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(OBJECT_DIRS):
	@-mkdir $(OBJECT_DIRS)

.PHONY: clean
clean: editor_clean simplesdl_clean centropy_clean ttslist_clean libgl_clean
	@-rm -rf $(OBJ_DIR)
	@-rm -rf $(EDITOR_OBJ_DIR)

.PHONY: fclean
fclean: clean editor_fclean simplesdl_fclean centropy_fclean ttslist_fclean libgl_fclean
	@-rm -rf $(NAME)
	@-rm -rf $(EDITOR_NAME)

.PHONY: re
re: fclean all

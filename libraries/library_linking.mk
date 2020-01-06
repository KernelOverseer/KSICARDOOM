# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    library_linking.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 15:45:08 by abiri             #+#    #+#              #
#    Updated: 2020/01/06 12:17:40 by oouklich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SIMPLESDL_MAKE = $(LIBS_DIR)/Ft_SimpleSDL
SIMPLESDL_NAME = $(SIMPLESDL_MAKE)/libftsimplesdl.a
SIMPLESDL_INC = -I $(SIMPLESDL_MAKE)/inc
SIMPLESDL_LINK = -L $(SIMPLESDL_MAKE) -lftsimplesdl

CENTROPY_MAKE = $(LIBS_DIR)/centropy
CENTROPY_NAME = $(CENTROPY_MAKE)/libcentropy.a
CENTROPY_INC = -I $(CENTROPY_MAKE)/includes
CENTROPY_LINK = -L $(CENTROPY_MAKE) -lcentropy

TTSLIST_MAKE = $(LIBS_DIR)/ttslist
TTSLIST_NAME = $(TTSLIST_MAKE)/libttslist.a
TTSLIST_INC = -I $(TTSLIST_MAKE)/includes
TTSLIST_LINK = -L $(TTSLIST_MAKE) -lttslist

LIBGL_MAKE = $(LIBS_DIR)/libgl
LIBGL_NAME = $(LIBGL_MAKE)/libgl.a
LIBGL_INC = -I $(LIBGL_MAKE)/includes
LIBGL_LINK = -L $(LIBGL_MAKE)

#SDL_INC = -I ~/.brew/Cellar/sdl2/$(SDL_VERSION)/include/SDL2\
#		  -I ~/.brew/Cellar/sdl2_ttf/$(SDL_TTF_VERSION)/include/SDL2

#SDL_LINK = -L ~/.brew/Cellar/sdl2/$(SDL_VERSION)/lib -lSDL2\
#		   -L ~/.brew/Cellar/sdl2_ttf/$(SDL_TTF_VERSION)/lib -lSDL2_ttf

SDL_INC = -I libraries/FT_SimpleSDL/sdl2_inc

SDL_DIR = libraries/FT_SimpleSDL/sdl2_frameworks
SDL2 = $(SDL_DIR)/SDL2.framework/Versions/A/SDL2
SDL2_IMAGE = $(SDL_DIR)/SDL2_image.framework/Versions/A/SDL2_image
SDL2_TTF = $(SDL_DIR)/SDL2_ttf.framework/Versions/A/SDL2_ttf
SDL2_MIXER = $(SDL_DIR)/SDL2_mixer.framework/Versions/A/SDL2_mixer
SDL_LINK = -F $(SDL_DIR) -framework SDL2 -framework SDL2_image\
		   -framework SDL2_ttf -framework SDL2_MIXER

#simplesdl rules

.PHONY: simplesdl
simplesdl: $(SIMPLESDL_NAME)

$(SIMPLESDL_NAME):
	@make -C $(SIMPLESDL_MAKE)

.PHONY: simplesdl_clean
simplesdl_clean:
	@make -C $(SIMPLESDL_MAKE) clean

.PHONY: simplesdl_fclean
simplesdl_fclean:
	@make -C $(SIMPLESDL_MAKE) fclean

#centropy rules

.PHONY: centropy
centropy: $(CENTROPY_NAME)

$(CENTROPY_NAME):
	@make -C $(CENTROPY_MAKE)

.PHONY: centropy_fclean
centropy_clean:
	@make -C $(CENTROPY_MAKE) clean

.PHONY: centropy_fclean
centropy_fclean:
	@make -C $(CENTROPY_MAKE) fclean

#ttslist rules

.PHONY: ttslist
ttslist: $(TTSLIST_NAME)

$(TTSLIST_NAME):
	@make -C $(TTSLIST_MAKE)

.PHONY: ttslist_clean
ttslist_clean:
	@make -C $(TTSLIST_MAKE) clean

.PHONY: ttslist_fclean
ttslist_fclean:
	@make -C $(TTSLIST_MAKE) fclean

#libgl rules

.PHONY: libgl
libgl: $(LIBGL_NAME)

$(LIBGL_NAME):
	@make -C $(LIBGL_MAKE)

.PHONY: libgl_clean
libgl_clean:
	@make -C $(LIBGL_MAKE) clean

.PHONY: libgl_fclean
libgl_fclean:
	@make -C $(LIBGL_MAKE) fclean

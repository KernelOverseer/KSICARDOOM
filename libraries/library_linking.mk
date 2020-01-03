# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    library_linking.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 15:45:08 by abiri             #+#    #+#              #
#    Updated: 2020/01/03 19:34:55 by abiri            ###   ########.fr        #
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

SDL_INC = -I ~/.brew/Cellar/sdl2/$(SDL_VERSION)/include/SDL2\
		  -I ~/.brew/Cellar/sdl2_ttf/$(SDL_TTF_VERSION)/include/SDL2

SDL_LINK = -L ~/.brew/Cellar/sdl2/$(SDL_VERSION)/lib -lSDL2\
		   -L ~/.brew/Cellar/sdl2_ttf/$(SDL_TTF_VERSION)/lib -lSDL2_ttf

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

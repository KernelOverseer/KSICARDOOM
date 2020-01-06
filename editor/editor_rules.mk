# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    editor_rules.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merras <merras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 18:34:05 by abiri             #+#    #+#              #
#    Updated: 2020/01/06 17:21:49 by oouklich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EDITOR_NAME = $(EDITOR_DIR)/editor
EDITOR_INC_DIR = $(EDITOR_DIR)/includes
EDITOR_SRC_DIR = $(EDITOR_DIR)/sources
EDITOR_OBJ_DIR = $(EDITOR_DIR)/objects

EDITOR_FILENAMES = editor_drawing.c\
editor_sector_list_draw.c\
graphical_engine_intersect.c\
graphical_engine_render.c\
graphical_object_constructors.c\
gui/button_constructor.c\
gui/button_draw.c\
gui/button_events.c\
gui/canvas_constructor.c\
gui/canvas_draw.c\
gui/checkbox_constructor.c\
gui/checkbox_draw.c\
gui/checkbox_event.c\
gui/gui_area.c\
gui/gui_area_constructors.c\
gui/gui_area_event_handlers.c\
gui/gui_area_events.c\
gui/gui_init.c\
gui/gui_load_assets.c\
gui/gui_lookup.c\
gui/gui_text.c\
gui/gui_tools.c\
gui/label_constructor.c\
gui/label_draw.c\
gui/slider_constructor.c\
gui/slider_draw.c\
gui/slider_events.c\
gui/textfield_constructor.c\
gui/textfield_draw.c\
gui/textfield_events.c\
gui_texture_display_addon.c\
gui_texture_selector_addon.c\
line_manipulation.c\
main.c\
main_interface_loading.c\
mouse_events.c\
player_manipulations.c\
render_mode.c\
scene_dumper.c\
sector_manipulation.c\
sector_properties.c\
types_serializer.c\
vectors.c

EDITOR_HEADER_FILES = editor.h\
					  ttsgui.h\
					  ttsgui_assets.h\
					  gui_button.h\
					  gui_checkbox.h\
					  gui_slider.h\
					  graphical_objects.h\
					  graphical_engine.h

EDITOR_SOURCES = $(addprefix $(EDITOR_SRC_DIR)/, $(EDITOR_FILENAMES))
EDITOR_OBJECTS = $(addprefix $(EDITOR_OBJ_DIR)/, $(EDITOR_FILENAMES:.c=.o))
EDITOR_HEADERS = $(addprefix $(EDITOR_INC_DIR)/, $(EDITOR_HEADER_FILES))
EDITOR_DIRS = $(sort $(dir $(EDITOR_OBJECTS)))
EDITOR_INCLUDES = -I $(EDITOR_INC_DIR) $(INCS)

EDITOR_RUNTIME_LINK = editor_runtime_link

.PHONY: editor
editor: $(EDITOR_NAME) editor_runtime_link

$(EDITOR_NAME): $(SIMPLESDL_NAME) $(CENTROPY_NAME) $(TTSLIST_NAME) $(EDITOR_OBJECTS)
	$(CC) $(FLAGS) $(EDITOR_OBJECTS) $(LINKS) -o $(EDITOR_NAME)

$(EDITOR_OBJECTS): $(EDITOR_OBJ_DIR)/%.o : $(EDITOR_SRC_DIR)/%.c $(EDITOR_HEADERS) | $(EDITOR_DIRS)
	$(CC) $(FLAGS) $(EDITOR_INCLUDES) -c $< -o $@

$(EDITOR_RUNTIME_LINK):
	install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 @loader_path/../$(SDL2) $(EDITOR_NAME)
	install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image @loader_path/../$(SDL2_IMAGE) $(EDITOR_NAME)
	install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf @loader_path/../$(SDL2_TTF) $(EDITOR_NAME)
	install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer @loader_path/../$(SDL2_MIXER) $(EDITOR_NAME)

$(EDITOR_DIRS):
	@-mkdir $(EDITOR_DIRS)

.PHONY: editor_clean
editor_clean:
	@-rm -rf $(EDITOR_OBJ_DIR)

.PHONY: editor_fclean
editor_fclean: editor_clean
	@-rm -rf $(EDITOR_NAME)

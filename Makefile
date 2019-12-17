NAME=doom_nukem

SRCS=doom_nukem.c
OBJS=$(SRCS:.c=.o)

LIBS_DIR=libs
OBJS_DIR=build
SRCS_DIR=srcs
OBJS_PATH=$(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS_PATH=$(addprefix $(SRCS_DIR)/, $(SRCS))
INCLUDES=includes

EDITOR_SRCS=main.c
EDITOR_OBJS=$(EDITOR_SRCS:.c=.o)

EDITOR_NAME=editor
EDITOR_OBJS_DIR=editor_build
EDITOR_SRCS_DIR=editor_srcs
EDITOR_OBJS_PATH=$(addprefix $(EDITOR_OBJS_DIR)/, $(EDITOR_OBJS))
EDITOR_SRCS_PATH=$(addprefix $(EDITOR_SRCS_DIR)/, $(EDITOR_SRCS))
EDITOR_INCLUDES=editor_includes


FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS_PATH) $(INCLUDES)/doom_nukem.h
	make -C $(LIBS_DIR)/centropy
	make -C $(LIBS_DIR)/simplist
	gcc $(OBJS_PATH) $(LIBS_DIR)/centropy/centropy.a $(LIBS_DIR)/simplist/simplist.a -lmlx -framework openGL -framework AppKit -o $(NAME)

$(EDITOR_NAME): $(EDITOR_OBJS_PATH) $(EDITOR_INCLUDES)/editor.h
	echo $(EDITOR_OBJS_PATH)
	make -C $(LIBS_DIR)/centropy
	make -C $(LIBS_DIR)/simplist
	gcc $(EDITOR_OBJS_PATH) $(LIBS_DIR)/centropy/centropy.a $(LIBS_DIR)/simplist/simplist.a -lmlx -framework openGL -framework AppKit -o $(EDITOR_NAME)

$(EDITOR_OBJS_PATH): $(EDITOR_OBJS_DIR)/%.o : $(EDITOR_SRCS_DIR)/%.c | $(EDITOR_OBJS_DIR)
	gcc $(FLAGS) -I$(EDITOR_INCLUDES) -I$(EDITOR_LIBS_DIR)/centropy/includes -I$(EDITOR_LIBS_DIR)/simplist/includes -c $< -o $@

$(OBJS_PATH): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	gcc $(FLAGS) -I$(INCLUDES) -I$(LIBS_DIR)/centropy/includes -I$(LIBS_DIR)/simplist/includes -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(EDITOR_OBJS_DIR):
	mkdir $(EDITOR_OBJS_DIR)

clean:
	make -C $(LIBS_DIR)/centropy clean
	make -C $(LIBS_DIR)/simplist clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBS_DIR)/centropy fclean
	make -C $(LIBS_DIR)/simplist fclean
	rm -rf $(NAME)

re: fclean all
	make -C $(LIBS_DIR)/centropy re
	make -C $(LIBS_DIR)/simplist re

NAME=doom_nukem

SRCS=doom_nukem.c

OBJS=$(SRCS:.c=.o)

LIBS_DIR=libs
OBJS_DIR=build
SRCS_DIR=srcs
OBJS_PATH=$(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS_PATH=$(addprefix $(SRCS_DIR)/, $(SRCS))
INCLUDES=includes

FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS_PATH) $(INCLUDES)/doom_nukem.h
	make -C $(LIBS_DIR)/centropy
	make -C $(LIBS_DIR)/simplist
	gcc $(OBJS_PATH) $(LIBS_DIR)/centropy/centropy.a $(LIBS_DIR)/simplist/simplist.a -lmlx -framework openGL -framework AppKit -o $(NAME)

$(OBJS_PATH): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	gcc $(FLAGS) -I$(INCLUDES) -I$(LIBS_DIR)/centropy/includes -I$(LIBS_DIR)/simplist/includes -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

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
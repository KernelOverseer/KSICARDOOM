# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merras <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 12:51:29 by merras            #+#    #+#              #
#    Updated: 2020/01/03 17:19:50 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcentropy.a

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_digitcount.c \
	ft_digitscount.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_noc.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_wordscount.c \
	ft_wordslens.c \
	array_to_list.c \
	ft_strjoin_free.c \
	t_string_del.c \
	ft_putchar_int.c \
	t_string_add_node.c \
	free_char_array.c \
	current_segment_size.c \
	t_string_length.c \
	char_array.c \
	is_flag.c \
	isalnum_check.c \
	is_dir.c \
	ft_isnumber.c \
	ft_isanumber.c \
	t_string_to_array.c

OBJS = $(SRCS:.c=.o)

SRCS_DIR = srcs
OBJS_DIR = build
INCLUDES = includes

SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS_PATH)
	ar rc $(NAME) $(OBJS_PATH)
	ranlib $(NAME)

$(OBJS_PATH): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean | all

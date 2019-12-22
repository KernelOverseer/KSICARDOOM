# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <abiri@1337.MA>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 14:42:53 by abiri             #+#    #+#              #
#    Updated: 2019/03/25 20:41:37 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_charreplace.c\
	  ft_count_if.c\
	  ft_endc.c\
	  ft_intsort.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_lstadd.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstnew.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_pow.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_base.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_putstrf.c\
	  ft_putwchar.c\
	  ft_sqrt.c\
	  ft_startc.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsort.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_strzero.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_wcharlen.c\
	  ft_wstrlen.c\
	  ft_wstrlen_min.c\
	  ft_fabs.c\
	  ft_ischarin.c\
	  ft_tabsize.c\
	  ft_strcjoin.c\
	  ft_tabfree.c\
	  ft_lstpush.c\
	  ft_charsetreplace.c\
	  ft_countchar.c\
	  ft_searchreplace.c\
	  ft_strreplace.c\
	  ft_strunescape.c\
	  ft_removechars.c\
	  ft_getnextvar.c\
	  ft_strsplitescape.c\
	  ft_strsplitcharset.c\
	  get_next_line.c

OBJ = $(SRC:.c=.o)
_lCYAN = \x1b[96m
_lYELLOW = \x1b[93m
_lGREEN = \x1b[92m
_lBLUE = \x1b[94m
_RED = \x1b[31m
_END = \x1b[0m
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME):
	@echo -e "gcc $(_lCYAN)$(FLAGS)$(_END) -I. -c $(_lYELLOW)$(SRC)$(_END)"
	@gcc $(FLAGS) -I. -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make -C ./ft_printf
clean:
	@rm -f $(OBJ)
	@make -C ./ft_printf clean
fclean: clean
	@rm -f $(NAME)
	@make -C ./ft_printf fclean
re: fclean all

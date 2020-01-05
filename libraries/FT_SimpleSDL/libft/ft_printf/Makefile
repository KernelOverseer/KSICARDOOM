# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 10:29:36 by abiri             #+#    #+#              #
#    Updated: 2019/05/20 13:16:13 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c\
	  ft_printf_itob.c\
	  ft_printf_justify.c\
	  ft_printf_number.c\
	  ft_printf_printdata.c\
	  ft_printf_parse.c\
	  ft_printf_putwchar.c\
	  ft_printf_itoal.c\
	  ft_printf_putlongf.c\
	  ft_printf_hex.c\
	  ft_printf_color.c

LFTSRC = ../ft_atoi.c\
		 ../ft_itoa.c\
		 ../ft_memalloc.c\
		 ../ft_memset.c\
		 ../ft_putchar.c\
		 ../ft_putstrf.c\
		 ../ft_putwchar.c\
		 ../ft_strchr.c\
		 ../ft_strdup.c\
		 ../ft_strequ.c\
		 ../ft_strjoin.c\
		 ../ft_strlen.c\
		 ../ft_strsub.c\
		 ../ft_strzero.c\
		 ../ft_tolower.c\
		 ../ft_wcharlen.c\
		 ../ft_wstrlen_min.c\
		 ../ft_putchar_fd.c\
		 ../ft_strcpy.c\
		 ../ft_wstrlen.c\
		 ../ft_startc.c\
		 ../ft_putstr.c\
		 ../ft_putnbr.c\
		 ../ft_putstr_fd.c

OBJ = $(SRC:.c=.o)
LFTDIR = ../
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(LFTSRC) -I $(LFTDIR)
	ar rc $(NAME) *.o
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all

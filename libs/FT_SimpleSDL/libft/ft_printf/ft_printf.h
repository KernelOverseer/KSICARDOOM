/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:56:32 by abiri             #+#    #+#             */
/*   Updated: 2019/01/18 23:58:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# define OCTAL "01234567"
# define BINARY "01"
# define HEX "0123456789abcdef"
# define HEX2 "0123456789ABCDEF"
# define DECIMAL "0123456789"
# define ULONGMAX 18446744073709551615U

typedef struct	s_print
{
	char		*flags;
	char		*arg;
	int			fieldw;
	int			precis;
	int			align;
}				t_print;

int				ft_printf(const char *format, ...);
t_print			*parse(char **str);
char			*ft_justify(t_print *data, char *str);
int				ft_printdata(t_print *data, va_list list);
char			*ft_print_num(long long nb, t_print *data);
char			*ft_itob(unsigned long long nbr, char *base);
int				ft_putcharf(t_print *data, char c);
int				ft_putstrf(char *str);
int				ft_putwcharf(t_print *data, int c);
char			*ft_putlongf(long long nb, t_print *data);
char			*ft_itoal(long long nbr);
char			*ft_itoalu(unsigned long long nbr);
char			*prefix(t_print *data, char type, char *str);
char			*numsign(t_print *data, char *str);
char			*addzeros(char *res, int zeroes, int p);
int				ft_putwstr(t_print *data, int *str);
char			*ft_puthex(long long nb, t_print *data);
void			ft_setcolor(t_print *data);

#endif

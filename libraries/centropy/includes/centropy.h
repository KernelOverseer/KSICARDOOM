/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:43:39 by merras            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTROPY_H
# define CENTROPY_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

# define F_GET(x, f) (x & (1 << f))
# define F_BGET(x, f) (x & f)
# define F_SET(x, f) (x |= (1 << f))
# define F_BSET(x, f) (x |= f)
# define F_UNSET(x, f) (x &= ~(1 << f))
# define F_BUNSET(x, f) (x &= ~f)

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_strcmp(const char *s1s, const char *s2s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haysta, const char *need, size_t len);
int				ft_strncmp(const char *s1s, const char *s2s, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s);
int				ft_wordscount(char const *s, char c);
int				*ft_wordslens(char const *s, char c);
char			*ft_noc(char *str, char c);
char			**ft_strsplit(char const *s, char c);
int				ft_digitscount(long long int n);
char			*ft_itoa(int n);
void			ft_putchar(char c);
int				ft_putchar_int(int c);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char const *s, int fd);

typedef struct	s_3tuple
{
	int i;
	int j;
	int k;
}				t_3tuple;

typedef struct	s_string
{
	char			*string;
	struct s_string	*next;
	struct s_string *prev;
}				t_string;
void			t_string_push(t_string **head, char *string);
t_string		*array_to_t_string(char **array);
char			*ft_strjoin_free(char *s1, char *s2, int p);
void			t_string_del(t_string *list);
int				t_string_length(t_string *list);
void			t_string_pop(t_string **head);
t_string		*t_string_create_node(t_string node_value);
void			t_string_del_node(t_string **head, t_string *node);
char			**t_string_to_array(t_string *list);
void			free_char_array(char **p);
int				current_segment_size(char *raw, char delimiter, int index);
int				array_length(char **array);
void			print_array(char **array);
int				is_flag(char *flag, char *supported);
int				isalnum_check(char *str);
t_string		*t_string_copy(t_string *list);
int				is_directory(char *filename);
int				ft_isnumber(char *string);

# define POSITIVE_NEGATIVE 0
int				ft_isanumber(char *string, int flags);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arnaud <Arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:39:16 by amagnan           #+#    #+#             */
/*   Updated: 2018/11/23 10:22:12 by Arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdarg.h>
# include <stdint.h>

# define BUFF_SIZE	42

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}					t_list;

void				ft_putchar(char c);
int					ft_atoi(const char *str);
void				ft_putstr(char const *s);
void				ft_putnbr(long long int n);
void				ft_putendl(char const *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hay, const char *n, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(const char *str, char c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strdup(const char *s1);

char				*ft_itoa_base(int64_t value, int base, const char *basetab);
void				ft_putstr0x(char *str);
char				*ft_itoa_base_long(intmax_t value, int base,
	const char *basetab);
int					b_printf(char *format, ...);
int					ft_str_is_print(char *str);
char				*ft_strndup(const char *s, int n);
char				*ft_strrevdup(const char *str);
void				ft_strswap(char **str1, char **str2);
char				*ft_strcat_from(char *str1, char *str2, int i);
char				*ft_strndup_from(char *str, int a, int b);
char				*ft_strcpy_from_to(char *str, int a, int b);
char				*ft_strdup_from(char *str, int a);
int					ft_is_operation(char c);
void				*ft_realloc(void *ptr, size_t size);
char				*ft_clean_str(char *str);
int					get_next_line(const int fd, char **line);
void				ft_mapdel(char **str);
char				**ft_mapalloc(int i, int j);
int 				ft_bin_to_dec(const char *bit);
int 				ft_first_c_from_end(char *str, char c);
char				*ft_strnjoin(const char *s1, const char *s2, size_t len);
unsigned long int	ft_hex_to_decimal(char *number);
unsigned long int 	ft_power(int n, int pow);
void				ft_exit_msg(char *str);
char				*ft_strfjoin(char *s1, char *s2);
char				*ft_char_to_bit(int nb);

#endif

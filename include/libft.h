/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:50:26 by ashea             #+#    #+#             */
/*   Updated: 2020/05/16 17:28:41 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				*ft_calloc(size_t count, size_t size);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char				*ft_strdup(const char *src);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst,
		void *(*f)(void *), void (*del)(void *));
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_lstsize(t_list *lst);

/* ************************************************************************** */
/*                           get_next_line                                    */
/* ************************************************************************** */

# define BUFFER_SIZE 32
char                 *ft_strljoin(char *s1, char *s2, size_t len);
int                  ft_get_next_line(int fd, char **line);

/* ************************************************************************** */
/*                               ft_printf                                    */
/* ************************************************************************** */

# include <stdarg.h>

typedef struct    s_size
{
    int            star;
    int            zero;
    int            dot;
}                t_size;
typedef struct    s_flag
{
    int            star;
    int            zero;
    int            dot;
    t_size        size;
}                t_flag;

int                ft_printf(const char *format, ...);
int                ft_strcmp(const char *s1, const char *s2);
int        ft_atoi_i(const char *str, size_t *i, va_list list);
char        *ft_itoa_base(long long n, int base, t_flag flag);
char        *ft_itoa_addres(unsigned long long n, t_flag flag);

int            ft_print_integer(va_list list, t_flag flag);
int            ft_print_unsignedint(va_list list, t_flag flag, int base, int is_toupper);
int            ft_print_address(va_list list, t_flag flag);
int            ft_print_char(va_list list, t_flag flag);
int            ft_print_string(va_list list, t_flag flag);
int            ft_print_percent(t_flag flag);
#endif

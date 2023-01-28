/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wewang <wewang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:24:07 by wewang            #+#    #+#             */
/*   Updated: 2022/11/23 12:05:07 by wewang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(char const *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, void const *src, size_t n);
void	*ft_memmove(void *str1, void const *str2, size_t count);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
void	*ft_memchr(void const *str, int c, size_t n);
int		ft_memcmp(void const *str1, void const *str2, size_t n);
char	*ft_strnstr(char const *big, char const *little, size_t len);
int		ft_atoi(char const *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_find_nl(char *str);
char	*ft_get_new_save(char *save);
char	*ft_get_line(char *save);
char	*ft_read_file(char *save, int fd);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
void	ft_print_character(char c, int *c_count);
void	ft_print_string(char *str, int *c_count);
void	ft_print_address_helper(unsigned long addr, int *c_count);
void	ft_print_address(unsigned long addr, int *c_count);
void	ft_print_decimal(int nb, int *c_count);
void	ft_print_unsigned_decimal(unsigned int nb, int *c_count);
void	ft_check_command(char command, va_list ap, int *c_count);
void	ft_print_hexa_l(int nb, int *c_count);
void	ft_print_hexa_u(int nb, int *c_count);
#endif
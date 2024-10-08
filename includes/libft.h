/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:40:37 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 21:40:37 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_lft
{
	void				*content;
	struct s_list_lft	*next;
}	t_list_lft;

void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *str);
unsigned int	ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *str, size_t dstsize);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s1, char c);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list_lft		*ft_lstnew(void *content);
void			ft_lstadd_front(t_list_lft **lst, t_list_lft *new);
int				ft_lstsize(t_list_lft *lst);
t_list_lft		*ft_lstlast(t_list_lft *lst);
void			ft_lstadd_back(t_list_lft **lst, t_list_lft *new);
void			ft_lstdelone(t_list_lft *lst, void (*del)(void *));
void			ft_lstclear(t_list_lft **lst, void (*del)(void *));
void			ft_lstiter(t_list_lft *lst, void (*f)(void *));
t_list_lft		*ft_lstmap(t_list_lft *lst, void *(*f)(void *), \
				void (*del) (void *));

// added
int				ft_isint(char *str);
int				ft_strcmp(const char *str1, const char *str2);
void            ft_exit_lft(int icode, char *str);
char            *ft_strldup(const char *src, size_t n);
char            **ft_split_multiple(char *str, char *str_c);

#endif
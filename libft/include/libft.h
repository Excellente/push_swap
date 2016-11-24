/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:36:11 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/24 09:50:00 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

typedef	struct	s_index	t_index;
struct	s_index
{
	int		i;
	int		j;
	int		index;
	char	*word;
	char	**sptr;
};

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(char *str);
int		ft_power(int b, int i);
int		ft_strequ(const char *s1, const char *s2);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
size_t	ft_strslen(char **s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strstr(char *str, char *substr);
char	*ft_strtrim(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, char const *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchar(const char *str, int c);
char	*ft_strcpy(char *dest, const char * src);
char	*ft_strncpy(char *dest, const char *src, size_t len);
char	*ft_strnew(size_t size);
char	**ft_strsplit(char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strsub(const char *s, unsigned int st, size_t n);
void	ft_putchar(int c);
void	ft_putnbr(int nb);
void	ft_putstr(char *s);
void	ft_putnbr_fd(int fd, int nb);
void	ft_putchar_fd(int fd, int c);
void	ft_putstr_fd(int fd, char *s);
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memccpy(void *dst, void *src, int c, size_t n);
void	*ft_memmove(void *dst, void *src, size_t n);
void	*ft_memchr(const void *s, int c,  size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_strclr(char *str);
void	ft_striter(char *s, void (*f)(char *));

#endif

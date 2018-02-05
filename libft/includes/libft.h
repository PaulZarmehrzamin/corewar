/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:09:19 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/30 14:42:12 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define BUFF_SIZE 512
# define FD_MAX 100

/*
** Error
*/
# define SYNTAX 100
# define EMPTYARGV 101
# define DUMPAV 102
# define OPTNAV 103
# define TOO_MANY_CHAMP 104
# define VERBAV 105
# define NO_CHAMP 106
# define SPEEDAV 107
# define SYSTEM 200
# define INVALID_FILE 201
# define MALLOC_FAILED 202
# define TOOSMALL 203

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_count_char(const char *str, int c);
int			ft_count_char_with_limit(const char *str, const char *end, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memrchr(const void *mem_start, const void *mem_end, int c);
int			ft_strnequ(const char *s1, const char *s2, size_t n);

void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putnchar(size_t n, int c);
void		ft_putstr(char const *s);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);

void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memjoin(const void *p1, size_t s1, const void *p2, size_t s2);
void		ft_memdel(void **ap);
void		ft_putmemory(void *mem, size_t size);

int			ft_strequ(char const *s1, char const *s2);
char		*ft_strtrim(char const *str);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_str_first_not(const char *str, int (*ft_is)(int));
char		*ft_str_first(const char *str, int (*ft_is)(int));

int			get_next_line(const int fd, char **line);
int			ft_read_file(int fd, char **out_content);
int			ft_read_file_with_filename(const char *filename,
								char **out_content);

void		ft_error(int status, char *str);
void		ft_error_fd(int status, char *str, int fd);
int			error(int id, int ret);
int			syntax_error(int id, int ret);
int			system_error(int id, int ret);

int			print_error(int ret, const char *message);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_isalpha(int c);
void		ft_putnbr(int n);
int			ft_isnum(const char *str);
char		**ft_strsplit(char const *s, char c);
char		*ft_strncpy(char *dst, const char *src, size_t n);
int			ft_len_tab(char **tab);
void		ft_memtabdel(void ***tab);
uint32_t	swap_byte_32(uint32_t value);
char		*ft_itoa(int n);

#endif

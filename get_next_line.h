/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:43:23 by nkannan           #+#    #+#             */
/*   Updated: 2024/02/06 08:43:23 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);
char *ft_strdup_gnl(const char *s1);
char *ft_strjoin_gnl(char const *s1, char const *s2);
size_t ft_strlen_gnl(const char *s);
char *ft_strchr_gnl(const char *s, int c);
void *ft_memcpy_gnl(void *dst, const void *src, size_t n);

#endif /* GET_NEXT_LINE_H */

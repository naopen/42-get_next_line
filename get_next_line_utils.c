/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:48:52 by nkannan           #+#    #+#             */
/*   Updated: 2024/02/06 08:48:52 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen_gnl(const char *s)
{
    size_t i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char *ft_strchr_gnl(const char *s, int c)
{
    while (s && *s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

char *ft_strjoin_gnl(char *s1, char *s2)
{
    char *new_str;
    size_t len1;
    size_t len2;

    if (!s1 && !s2)
        return (NULL);
    len1 = ft_strlen_gnl(s1);
    len2 = ft_strlen_gnl(s2);
    new_str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!new_str)
        return (NULL);
    ft_memcpy_gnl(new_str, s1, len1);
    ft_memcpy_gnl(new_str + len1, s2, len2);
    new_str[len1 + len2] = '\0';
    free(s1);
    return (new_str);
}

void *ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}


char *extract_line_from_remainder(char **remainder)
{
    char *line;
    char *new_remainder;
    char *newline_ptr;
    size_t line_len;

    if (!*remainder)
        return (NULL);
    newline_ptr = ft_strchr_gnl(*remainder, '\n');
    if (newline_ptr)
    {
        line_len = newline_ptr - *remainder + 1;
        line = ft_substr_gnl(*remainder, 0, line_len);
        new_remainder = ft_strdup_gnl(newline_ptr + 1);
        free(*remainder);
        *remainder = new_remainder;
        if (**remainder == '\0')
        {
            free(*remainder);
            *remainder = NULL;
        }
    }
    else
    {
        line = ft_strdup_gnl(*remainder);
        free(*remainder);
        *remainder = NULL;
    }
    return (line);
}

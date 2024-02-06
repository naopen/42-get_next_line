/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:46:56 by nkannan           #+#    #+#             */
/*   Updated: 2024/02/06 08:46:56 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *remainder;
    char *line;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    line = NULL;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0'; // Ensure null-termination
        remainder = ft_strjoin_gnl(remainder, buffer);
        if (ft_strchr_gnl(remainder, '\n'))
            break;
    }

    if (bytes_read < 0)
        return (NULL);

    line = extract_line_from_remainder(&remainder);
    if (!*line)
    {
        free(line);
        return (NULL);
    }

    return (line);
}

// The following functions need to be implemented in get_next_line_utils.c

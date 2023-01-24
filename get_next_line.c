/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:44:35 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/24 22:58:28 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *line;
    char *to_free;
    char *temp;
    int bytes_read;
    char buffer[BUFFER_SIZE + 1];

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        if (line)
            free(line);
        return (NULL);
    }
    while (!ft_strchr(line, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)))
    {
        if (bytes_read == -1)
        {
            free(line);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        if (!line)
            temp = ft_strdup(buffer);
        else
            temp = ft_strjoin(line, buffer);
        line = temp;
    }
    bytes_read = ft_strchr(line, '\n') - line;
    temp = ft_substr(line, 0, bytes_read + 1);
    to_free = line;
    line = ft_substr(line, bytes_read + 1, ft_strlen(line) - bytes_read);
    free(to_free);
    return (temp);
}




// int main(void)
// {
//     int     fd;
    
//     fd = open("file.txt", O_RDONLY);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);

// }
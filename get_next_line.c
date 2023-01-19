/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:44:35 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/19 18:29:11 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    static char buffer[BUFF_SIZE];
    static int offset;
    static int bytes_read;
    int i;
    char *line;
	// char *c;

	line = NULL;
	i = 0;
	
    if (fd < 0)
        return NULL;    
    if (!(line = (char*)malloc(sizeof(char))))
		return NULL;
	while (42)
	{
		if (offset == bytes_read)
		{
			bytes_read = read(fd, buffer, BUFF_SIZE);
			offset = 0;
			if (bytes_read == 0)
			{
				return NULL;
				free(line);
			}
		}
		line[i] = buffer[offset];
		offset++;
		if (line[i] == '\n')
			break;
	}
	line[i] = '\n';
	i++;
	line[i] = '\0';
	return (line);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:44:35 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/12 15:38:43 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd)
{   
    char    *buf;
    char    *line;
    int     i = 0;
    int     j = 0;
    int     k = 0;
    static int offset = 0;

    i = offset;
    printf("i = %d\n", i);
    read(fd, buf, 1000);
    line = (char *)malloc(sizeof(buf));
    while (buf[i] != '\n')
    {
        line[k] = buf[i];
        k++;
        i++;
    }
    line[i++] = '\n';
    line[i++] = '\0';
    
    while (line[j])
    {
        write(1, &line[j], 1);
        j++;
    }
    
    free(line);
    offset = i - 1;
    printf("\noffset: %d\n\n", offset);
    
}


int main(void)
{
    int     fd;
    
    fd = open("file.txt", O_RDONLY);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    
}
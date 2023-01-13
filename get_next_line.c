/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:44:35 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/13 16:29:54 by nipostni         ###   ########.fr       */
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
    int     len = 0;
    
    static int offset = 0;

    i = offset;
    printf("i = %d\n", i);
    read(fd, buf, 100);
    while (buf[len])
        len++;
    line = (char *)malloc(sizeof(char *) * len);
    while (buf[i] != '\n')
    {
        if (buf[i] == '\0')
            break;
        line[k++] = buf[i++];
    }
    line[i++] = '\n';
    line[i++] = '\0';
    offset = i - 1;
    return(line);
}


int main(void)
{
    int     fd;
    
    fd = open("file.txt", O_RDONLY);
    printf("%s", (get_next_line(fd)));
    printf("%s", (get_next_line(fd)));
    printf("%s", (get_next_line(fd)));
    printf("%s", (get_next_line(fd)));
    printf("%s", (get_next_line(fd)));
    printf("%s", (get_next_line(fd)));

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:44:35 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/12 14:30:43 by nipostni         ###   ########.fr       */
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
    char    *line[100];
    int     i = 0;

    buf = (char *)malloc(100 * sizeof(char));
    buf[101] = '\0';
    

    read(fd, buf, 100);
    while (buf[i] != '\n')
    {
        write(1, &buf[i], 1);
        i++;
    }
    
    // printf("%s", buf);
    
}


int main(void)
{
    int     fd;
    
    fd = open("file.txt", O_RDONLY);
    get_next_line(fd);
    
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:44:35 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/11 16:30:06 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char *get_next_line(int fd)
{
   
    
}


int main(void)
{
    int     fd;
    char    *buf;
    int     i;

    i = 0;
    fd = open("file.txt", O_RDONLY);

    while (buf[i] != '\n')
    {
        i++;
    }

    read(fd, buf, i - 1);

    printf("%d\n", i);
    printf("%s", buf);
    
    
}
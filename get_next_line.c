/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:44:35 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/12 13:26:50 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char *get_next_line(int fd)
{
    char    *buf[500];
    printf("%d\n", fd);
    read(fd, buf, 500);
    printf("%s", buf);
}


int main(void)
{
    int     fd;
    
    fd = open("file.txt", O_RDONLY);
    get_next_line(fd);
    
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:23:54 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/26 17:46:08 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_one_line(int fd, char *stash)
{
	char				buf[BUFFER_SIZE + 1];
	char				*temp;
	int					bytes_read;

	bytes_read = 1;
	while (42)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (stash)
				free(stash);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		if (!stash)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(stash, buf);
		stash = temp;
		if (ft_strchr(stash, '\n') || bytes_read == 0)
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char			*stash;
	char				*temp;
	char				*line;
	int					len;

	if (fd < 0 || fd > 1023)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	stash = get_one_line(fd, stash);
	if (!stash)
		return (NULL);
	len = ft_strchr(stash, '\n') - stash;
	line = ft_substr(stash, 0, len + 1);
	temp = stash;
	stash = ft_substr(stash, len + 1, (ft_strlen(stash) - len));
	free(temp);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("file.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	return 0;
// }

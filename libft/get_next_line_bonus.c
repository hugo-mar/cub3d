/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:05:03 by divalent          #+#    #+#             */
/*   Updated: 2024/05/27 16:38:39 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int				end;
	int				check;
	char			*line;

	check = 0;
	end = 0;
	line = NULL;
	while (BUFFER_SIZE > 0 && fd >= 0 && fd < FOPEN_MAX)
	{
		if (*buffer[fd])
			line = find_newline(buffer[fd], &check, line);
		if (buffer[fd][0] == '\0' && check == 0)
		{
			end = read(fd, buffer[fd], BUFFER_SIZE);
			if (end < 0)
				buff_cleaner(buffer[fd], &check, 1);
			if ((end <= 0 && !line) || end < 0)
				return (buff_cleaner(line, &check, end));
			buffer[fd][end] = '\0';
		}
		if ((line && check == 1) || (buffer[fd][0] == '\0' && end == 0))
			return (line);
	}
	return (NULL);
}

/* 
int main(void)
{
    int		fd3;
	int 	fd4;
	char	*line;

    fd3 = open("read_error.txt", O_RDONLY);
	fd4 = open("lines_around_10.txt", O_RDONLY);

	printf("line: %s\n", line = get_next_line(fd3));
	free(line);
	printf("line: %s\n", line = get_next_line(fd4));
	free(line);
	printf("line: %s\n", line = get_next_line(fd3));
	free(line);
	printf("line: %s\n", line = get_next_line(fd4));
	free(line);
	
    close(fd3);
	close(fd4);
	return (0);
} */
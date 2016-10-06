/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 14:17:13 by dalexand          #+#    #+#             */
/*   Updated: 2016/10/06 13:36:23 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

int		increase_buffer_size(char **buffer, int *buffer_size, int increment)
{
	char	*new_buffer;
	int		new_buffer_size;
	int		i;

	new_buffer_size = *buffer_size + increment;
	if (!(new_buffer = ft_memalloc(sizeof(char) * (new_buffer_size + 1))))
		return (-1);
	i = 0;
	while (i <= *buffer_size)
	{
		new_buffer[i] = (*buffer)[i];
		i++;
	}
	free(*buffer);
	*buffer = new_buffer;
	*buffer_size = *buffer_size + increment;
	return (0);
}

int		handle_eof(char **line, char **buffer, int *buffer_size,
	int string_size)
{
	if (string_size == *buffer_size)
		if (increase_buffer_size(buffer, buffer_size, 1) == -1)
		{
			free(buffer);
			return (-1);
		}
	*line = *buffer;
	(*buffer)[string_size] = '\0';
	return (string_size ? 1 : 0);
}

int		handle_end_of_line(char **line, char *buffer, int string_size)
{
	*line = buffer;
	buffer[string_size] = '\0';
	return (1);
}

int		my_read(const int fd, char *buffer)
{
	static int		i = 0;
	static char		*kept = NULL;
	static int		ret = 0;

	if (!(kept))
		kept = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if (i == ret)
	{
		ret = read(fd, kept, BUFF_SIZE);
		i = 0;
	}
	if (ret < 0)
	{
		return (-1);
	}
	if (ret > 0)
	{
		buffer[0] = kept[i];
		i++;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char	*buffer;
	int		buffer_size;
	int		string_size;
	int		result;

	string_size = 0;
	buffer_size = BUFF_SIZE + string_size;
	if ((!(buffer = ft_memalloc((sizeof(char) * (buffer_size + 1)))))
		|| line == NULL || fd < 0 || fd == 1 || fd == 2)
		return (-1);
	while (1)
	{
		result = my_read(fd, buffer + string_size);
		if ((result == -1) || (string_size == buffer_size &&
			increase_buffer_size(&buffer, &buffer_size, buffer_size) == -1))
		{
			free(buffer);
			return (-1);
		}
		if (result == 0)
			return (handle_eof(line, &buffer, &buffer_size, string_size));
		if (buffer[string_size] == '\n')
			return (handle_end_of_line(line, buffer, string_size));
		string_size = string_size + result;
	}
}

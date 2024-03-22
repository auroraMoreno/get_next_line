/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:58:16 by aumoreno          #+#    #+#             */
/*   Updated: 2024/03/18 18:15:34 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_new_line(char *stash, size_t break_pos)
{
	char	*line;

	line = ft_substr(stash, 0, break_pos);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_clean_stash(char *stash, size_t break_pos, size_t len)
{
	char	*new_stash;

	if (!stash[len])
		return (ft_free(&stash));
	new_stash = ft_substr(stash, break_pos, len);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*ft_read_line(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer = '\0';
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			stash = ft_strjoin(stash, buffer);
		}
	}
	free(buffer);
	return (stash);
}

char	*ft_free(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	size_t		break_pos;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// add condition that checks si en el stash ya hay una salto linea 
	// si no hay un salto de linea we read
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	len = ft_strlen(stash);
	if (ft_strchr(stash, '\n'))
		break_pos = ft_strchr(stash, '\n') - stash + 1;
	else
		break_pos = len;
	line = ft_get_new_line(stash, break_pos);
	if (!line)
		return (ft_free(&stash));
	stash = ft_clean_stash(stash, break_pos, len - break_pos);
	return (line);
}

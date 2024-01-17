/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:49 by aumoreno          #+#    #+#             */
/*   Updated: 2024/01/17 18:57:58 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
    char *line;
    char *buffer;
    // char static *stash;
    ssize_t bytes_read;
    
    bytes_read = 0;
    buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
    line = malloc(bytes_read + 1);
    
    ft_memcpy(line, buffer, bytes_read);
    line[bytes_read] = '\0';
    return line;
}

int main()
{
    int fd = open("prueba.txt",O_RDWR);
    char* result = get_next_line(fd);
    printf("%s", result);
    free(result);
    return (0);
}


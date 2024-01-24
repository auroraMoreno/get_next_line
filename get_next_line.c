/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:49 by aumoreno          #+#    #+#             */
/*   Updated: 2024/01/24 14:20:29 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
    char *line;
    char *buffer;
    // static char *stash; // alocar esto 
    ssize_t bytes_read;
    int i;
    bytes_read = 0;
    buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
    line = malloc(bytes_read + 1);
    
    // si el bytes_read es 0, significa que llegó al final del fichero
    if(bytes_read == 0)
    {
        //si llega al final del fichero hay que devolver 0 (según subject)
        free(buffer);
        return (0);
    }
    
    i = 0;
    while(*buffer != '\n')
    {
        line[i] = *buffer;
        i++;
        buffer++;
    }

    if(*buffer == '\n'){
        line[i] = *buffer;
        i++;
    }

    line[i] = '\0';
    //free(buffer);
    return (line);
}

int main()
{
    int fd = open("prueba.txt",O_RDWR);
    char* result = get_next_line(fd);
    printf("%s", result);
    free(result);
    return (0);
}


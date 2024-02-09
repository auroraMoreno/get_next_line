/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:17:44 by aumoreno          #+#    #+#             */
/*   Updated: 2024/02/09 12:35:54 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// aqui es donde yo llamo al buffer
char *ft_read_line(int fd, char *stash)
{
    char *buffer; 
    ssize_t bytes_read; 
    buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
    if(!buffer)
        return (NULL);
    bytes_read = 1; // esto es 1 porque si no, nunca entra en el bucle 
    while(!ft_strrchr(buffer, '\n') && bytes_read > 0) //esto no 
    {
        bytes_read = read(fd,buffer,BUFFER_SIZE);
        // si es mayor que 0 => lo guardo en el stash
        if(bytes_read > 0)
        {
            // stash es lo que ya tiene dentro asi que hay que añadir 
            // lo del buffer a lo que ya tiene el stash 
            buffer[bytes_read] = '\0';
            stash = ft_strjoin(stash, buffer);
        }
    }
    free(buffer);
    // aqui tengo que liberar el stash con ft_free y return line
    return stash; 

}

char	*get_next_line(int fd)
{
    static char *stash = NULL; 
    char *line; 
    if(fd < 1 || BUFFER_SIZE < 1)
        return NULL; 
    line = ft_read_line(fd, stash);
    return (line);
}


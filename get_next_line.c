/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:17:44 by aumoreno          #+#    #+#             */
 /*   Updated: 2024/02/14 11:32:45 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char *ft_get_new_line(char *stash)
{
    // conseguir el length del stash hasta el salto de linea (incluida) 
    // alocar la memoria de line accordinlgy 
    // inicializamos con el valor del substr 
    char *line; //  aloco la memoria según el length del stash hasta el salto de linea 
    //char *aux; // aqui meto lo que me sobra del stash? 
	int len; 

	// tmb podría usar el strlcopy para copiar dentro de line lo que haya en el stash? 
	len = 0;
	while()
	{
		len++;
		// ft_strlcpy(line, stash, );
	}
	
	line = ft_substr(stash,0,len);
    return line; 
}*/


// aqui es donde yo llamo al buffer
char *ft_read_line(int fd, char *stash)
{
    char *buffer; 
    ssize_t bytes_read; 
    buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
    if(!buffer)
        return (NULL);
    bytes_read = 1; // esto es 1 porque si no, nunca entra en el bucle 
    while(!ft_strchr(buffer, '\n') && bytes_read > 0) //esto no 
    {
        bytes_read = read(fd,buffer,BUFFER_SIZE);
        // si es mayor que 0 => lo guardo en el stash
        if(bytes_read > 0)
        {
            // stash es lo que ya tiene dentro asi que hay que añadir 
            // lo del buffer a lo que ya tiene el stash 
            //buffer[bytes_read] = '\0';
            stash = ft_strjoin(stash, buffer);
        }
    }
    free(buffer);
    return (stash); 

}

char	*get_next_line(int fd)
{
    static char *stash = NULL; 
    char *line; 
    if(fd < 0 || BUFFER_SIZE < 0)
        return NULL; 
    line = ft_read_line(fd, stash);
    return (line);
}


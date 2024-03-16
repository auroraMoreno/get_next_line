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


char *ft_get_new_line(char *stash, size_t break_pos)
{
    // conseguir el length del stash hasta el salto de linea (incluida) 
    // alocar la memoria de line accordinlgy 
    // inicializamos con el valor del substr '
    // tmb puedo usar strlcopy? 
    char *line; //  aloco la memoria según el length del stash hasta el salto de linea 
    //char *aux; // aqui meto lo que me sobra del stash? 
    // uso strchr para conseguir hasta el salto de linea
    //line = ft_strchr(stash, '\n'); // hacer un método para calcular el indice de donde está el \n
    line = ft_substr(stash,0,break_pos);
    if(!line)
        return (NULL);

    return (line); 
}

// tiene que actualizar el stash y dejar solo desde el salto de linea
// hasta el final 
char *ft_clean_stash(char *stash, size_t break_pos, size_t len)
{
    char *new_stash;

    if(!stash[len])
        return (ft_free(&stash));

    new_stash = ft_substr(stash, break_pos, len);
    if(!new_stash)
        return (NULL);
    return (new_stash);
}


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
            buffer[bytes_read] = '\0';
            stash = ft_strjoin(stash, buffer);
        }
    }
    free(buffer);
    return (stash); 

}

char *ft_free(char **stash){
    free(*stash);
    *stash = NULL;
    return *stash;
}

char	*get_next_line(int fd)
{
    static char *stash = NULL; 
    char *line; 
    size_t break_pos; 
    size_t len;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
        
    stash = ft_read_line(fd, stash); // leo todo el buffer size, "hasta el salto de linea"
    // añadir condicion por si viniera nulo el stash 
    if(!stash)
        return (NULL);
    len = ft_strlen(stash); // la necesito para más tarde
    //compruebo si el stash tiene \n:
    if(ft_strchr(stash, '\n'))
        //consigo la posición de donde está el salto de linea en stash
        break_pos =  ft_strchr(stash, '\n') - stash + 1; 
    else
        break_pos = len;
    // actualizo linea
    line = ft_get_new_line(stash, break_pos);
    // si no hay nada en la linea => free 
    if(!line)
        return (ft_free(&stash));
    // tengo que actualizar el stash
    // le paso desde el "indice" del salto de linea en adelante
    stash = ft_clean_stash(stash, break_pos, len - break_pos); 
    return (line);
}


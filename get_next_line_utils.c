/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:37:07 by aumoreno          #+#    #+#             */
/*   Updated: 2024/03/16 11:04:20 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


// s1 = stash || s2 = buffer 
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

// aqui habrá que añadir una comprobación porque la primera vez 
// el stash vendrá vacío
	if(!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		
		if(!s1)
			return (NULL);
		
		s1[0] = 0;
		
	}

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		str[len1] = s2[i];
		len1++;
	}
	//str[len1] = '\0';
	return (str);

}


// para buscar el \n voy a usar strchr que 
// The strchr() function returns a pointer to the first occurrence of the character c in the string s:
char	*ft_strchr(char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != (char)c)
	{
		if (*aux == '\0')
		{
			return (0);
		}
		aux++;
	}
	return (aux);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = (void *)malloc(nmemb * size);
	if (str == 0)
		return (0);
	str[0] = '\0';
	return (str);
}

/*
	s = stash 
	start 
	len
*/
char	*ft_substr(char const *stash, unsigned int start, size_t len)
{
	char	*substr;
	size_t 	i;

	if (!stash)
		return (0);
	if (start > ft_strlen(stash))
	{
		substr = ft_calloc(1, 1); 
		return (substr);
	}
	if (ft_strlen(stash) - start < len)
		len = ft_strlen(stash) - start;
	substr = ft_calloc((len + 1), 1);
	if (!substr)
		return (0);
		
	i = 0;
	while (i < len && stash[start + i])
    {
        substr[i] = stash[start + i];
        i++;
    }
	substr[i] = '\0';
	return (substr);
}

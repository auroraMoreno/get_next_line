/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:37:07 by aumoreno          #+#    #+#             */
/*   Updated: 2024/02/09 12:39:48 by aumoreno         ###   ########.fr       */
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

// s1 = stash s2 = buffer 
char	*ft_strjoin(char const *s1, char const *s2)
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
	str[len1] = '\0';
	return (str);

}


// para buscar el \n voy a usar strrchr que 
// busca la ultima vez que se encontró ese char en concreto
//   The strrchr() function returns a pointer to the last occurrence of the character c in the string s.

char	*ft_strrchr(const char *s, int c)
{
	const char	*innit;
	char		ctr;

	innit = s;
	ctr = c;
	while (*s)
		s++;
	while (*s != ctr)
	{
		if (s == innit)
			return (0);
		s--;
	}
	return ((char *) s);
}

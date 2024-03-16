/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:37:07 by aumoreno          #+#    #+#             */
/*   Updated: 2024/03/16 16:47:10 by aumoreno         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[j + i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != (char)c)
	{
		if (*aux == '\0')
			return (0);
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

char	*ft_substr(char const *stash, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

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

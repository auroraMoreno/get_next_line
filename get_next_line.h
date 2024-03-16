/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:37:26 by aumoreno          #+#    #+#             */
/*   Updated: 2024/03/16 11:03:04 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif


char            *get_next_line(int fd);
char            *ft_read_line(int fd, char *stash);
char            *ft_get_new_line(char *stash, size_t break_pos);
char            *ft_free(char **stash);
size_t          ft_strlen(const char *s);
char	        *ft_strjoin(char *s1, char *s2);
char	        *ft_strchr(char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
// unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strrchr(const char *s, int c);


#endif
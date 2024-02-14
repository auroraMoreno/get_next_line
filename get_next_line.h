/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:37:26 by aumoreno          #+#    #+#             */
/*   Updated: 2024/02/09 16:35:47 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif


char            *get_next_line(int fd);
char            *ft_read_line(int fd, char *stash);
size_t          ft_strlen(const char *s);
char	        *ft_strjoin(char *s1, char *s2);
char	        *ft_strchr(char *s, int c);


#endif
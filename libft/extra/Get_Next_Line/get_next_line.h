/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:24:20 by insoares          #+#    #+#             */
/*   Updated: 2024/10/24 16:56:00 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_another_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *new_str, char *src, size_t size);

char	*get_next_line(int fd);
char	*get_stash(int fd, char *stash);
char	*get_line_(char *stash);
char	*get_left_overs(char *stash);
char	*free_data(char *stash, char *buff);

#endif

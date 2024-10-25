/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:58:59 by insoares          #+#    #+#             */
/*   Updated: 2024/10/24 16:55:50 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_another_strjoin(char *stash, char *buff)
{
	char	*new_str;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	new_str = ((char *)malloc((sizeof(char)) * (ft_strlen(stash)
					+ (ft_strlen(buff) + 1))));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, stash, (ft_strlen(stash) + 1));
	ft_strlcpy((new_str + ft_strlen(stash)), buff, (ft_strlen(buff) + 1));
	free(stash);
	return (new_str);
}

char	*ft_strchr(const char *buff, int space)
{
	int	i;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\0')
	{
		if (buff[i] == ((char)space))
			return (((char *)buff) + i);
		i++;
	}
	if (buff[i] == ((char)space))
		return (((char *)buff) + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *new_str, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[j] != '\0' && j < (size -1))
	{
		new_str[j] = src[j];
		j++;
	}
	new_str[j] = '\0';
	return (i);
}

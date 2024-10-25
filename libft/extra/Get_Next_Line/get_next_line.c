/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:58:56 by insoares          #+#    #+#             */
/*   Updated: 2024/10/24 16:56:57 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_stash(fd, stash);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line = get_line_(stash);
	stash = get_left_overs(stash);
	return (line);
}

char	*get_stash(int fd, char *stash)
{
	char		*buff;
	int			bytes;

	bytes = BUFFER_SIZE;
	buff = (char *)malloc(sizeof(char) * (bytes + 1));
	if (!buff)
		return (NULL);
	*buff = '\0';
	while (!ft_strchr(buff, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free_data(stash, buff));
		buff[bytes] = '\0';
		stash = ft_another_strjoin(stash, buff);
		if (!stash || !(*stash))
			return (free_data(stash, buff));
	}
	free(buff);
	return (stash);
}

char	*get_line_(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(line, stash, (i + 1));
	return (line);
}

char	*get_left_overs(char *stash)
{
	int		i;
	int		j;
	char	*leftovers;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	leftovers = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	j = 0;
	while (stash[i] != '\0')
		leftovers[j++] = stash[i++];
	leftovers[j] = '\0';
	free(stash);
	return (leftovers);
}

char	*free_data(char *stash, char *buff)
{
	free(buff);
	free(stash);
	return (NULL);
}

/* int	main(void)
{
	int		fd;
	char	*s;
	int i = 0;

	fd = open("example.txt", O_RDONLY);
	s = get_next_line(fd);
	while (i < 6)
	{
		printf("%s", s);
		s = get_next_line(fd);
		i++;
	}
	//printf("%s", s);
	return (0);
} */

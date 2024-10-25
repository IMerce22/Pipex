/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:02:12 by insoares          #+#    #+#             */
/*   Updated: 2024/04/29 09:55:01 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	word_c(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

size_t	char_c(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != c && s[counter] != '\0')
		counter++;
	return (counter);
}

char	**ft_free_str(char **s, size_t c_len)
{
	while (c_len--)
		free(s[c_len]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	c_len;
	size_t	j;

	i = 0;
	j = 0;
	str = (char **) malloc((sizeof(char *)) * ((word_c(s, c) + 1)));
	if (!str)
		return (NULL);
	while (i < (word_c(s, c)))
	{
		while (s[j] == c)
			j++;
		c_len = (char_c(s + j, c));
		str[i] = (char *) malloc((sizeof(char)) * (c_len + 1));
		if (!str[i])
			return (ft_free_str(str, i));
		ft_strlcpy(str[i], s + j, (c_len + 1));
		j += c_len;
		i++;
	}
	str[i] = NULL;
	return (str);
}
/* int	main(void)
{
	char	s[] = "Be stonger then your strongest exuse!";
	char	c;
	
	c = 32;
	ft_split(s, c);
	printf("%s", s);
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:18 by insoares          #+#    #+#             */
/*   Updated: 2024/04/22 19:26:39 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	len;	

	if (!s1)
		return (NULL);
	len = (ft_strlen(s1));
	if ((ft_strlen(s1) == 0))
		return (ft_strdup(""));
	i = 0;
	while (s1[i] != '\0' && ft_check(set, s1[i]))
		i++;
	while (i < len && ft_check(set, s1[len - 1]))
		len--;
	s = (char *) malloc((sizeof(char)) * (len + 1 - i));
	if (!s)
		return (NULL);
	ft_strlcpy (s, s1 + i, len - i + 1);
	return (s);
}
/* 
int	main(void)
{
	return (0);
} */

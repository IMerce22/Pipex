/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:47 by insoares          #+#    #+#             */
/*   Updated: 2024/04/17 16:39:08 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ((char)c))
			return (((char *)s) + i);
		i++;
	}
	if (s[i] == ((char)c))
		return (((char *)s) + i);
	return (NULL);
}
/* int	main(void)
{
	const char	s[] = "olamunmdo";
	int	c;

	c = 'O';
	printf("%s\n", ft_strchr(s, c));
	printf("%s", strchr(s, c));
	return (0);
} */
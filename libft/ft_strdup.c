/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:26:29 by insoares          #+#    #+#             */
/*   Updated: 2024/04/20 14:27:02 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;
	int		c;

	i = ft_strlen(s);
	copy = ((char *)malloc(sizeof(char) * i + 1));
	if (!copy)
		return (NULL);
	c = 0;
	while (s[c])
	{
		copy[c] = s[c];
		c++;
	}
	copy[c] = '\0';
	return (copy);
}
/* int	main(void)
{
	const char	s[]= "0";

	ft_strdup(s);
	printf ("%s\tminha\n", s);
	strdup(s);
	printf ("%s\toriginal", s);
	return (0);
} */

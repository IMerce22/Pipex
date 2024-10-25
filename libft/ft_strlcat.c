/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:17:30 by insoares          #+#    #+#             */
/*   Updated: 2024/04/22 15:32:41 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	t_dest;
	size_t	t_src;
	size_t	i;

	i = 0;
	t_dest = ft_strlen(dest);
	t_src = ft_strlen(src);
	if (t_dest > size || size == 0)
		return (t_src + size);
	while ((t_dest + i < size - 1) && src[i] != '\0')
	{
		dest[t_dest + i] = src[i];
		i++;
	}
	dest[t_dest + i] = '\0';
	return (t_dest + t_src);
}
/* int	main(void)
{
	const char	src[] = "lorem ipsum dolor sit amet";
	char	dest[] = "a";
	size_t	n;

	n = 15;
	printf("%zu\n", ft_strlcat(dest, src, n));
	printf("%s", dest);
	return (0);
} */
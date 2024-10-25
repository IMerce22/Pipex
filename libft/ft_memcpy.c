/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:21:22 by insoares          #+#    #+#             */
/*   Updated: 2024/04/16 16:48:19 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}
/*int	main(void)
{
	const char	src[] = "Ola";
	char	dest[] = "Mundo";
	size_t	n;

	n = 3;
	printf("%s\n", (char *)ft_memcpy(dest, src, n));
	printf("%s", (char *)memcpy(dest, src, n));
	return (0);
}*/
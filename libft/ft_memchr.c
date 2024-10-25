/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:26:55 by insoares          #+#    #+#             */
/*   Updated: 2024/04/18 16:25:09 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	i = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == chr)
			return (str + i);
		i++;
	}
	return (0);
}
/* int	main(void)
 {
	char	s[] = "UmaCasa";
	int	c;
	size_t	n;

	c = 'C';
	n = 7;
	ft_memchr(s, c, n);
	return (0);
 } */
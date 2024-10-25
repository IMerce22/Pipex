/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:25:37 by insoares          #+#    #+#             */
/*   Updated: 2024/04/18 18:57:56 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	n;

	b = 0;
	l = 0;
	if (little[l] == '\0')
		return ((char *)big);
	while (big[b] != '\0' && l < len)
	{
		n = b;
		while (big[b + l] == little[l] && big[b + l] != '\0' && n < len)
		{
			if (little[l + 1] == '\0')
				return ((char *)big + b);
			l++;
			n++;
		}
		b++;
		l = 0;
	}
	return (0);
}
/* int	main(void)
{
	char	big[] = "Mundo!";
	char	little[] = "Ola";
	size_t	len;

	len = 2;
	printf("%s", ft_strnstr(big, little, len));
	return (0);
} */
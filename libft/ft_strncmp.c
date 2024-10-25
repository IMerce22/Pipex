/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:36:08 by insoares          #+#    #+#             */
/*   Updated: 2024/04/18 15:41:32 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sr1;
	unsigned char	*sr2;

	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	i = 0;
	while ((n > 0 && (sr1[i] != '\0' || sr2[i] != '\0')))
	{
		if (sr1[i] != sr2[i])
			return (sr1[i] - sr2[i]);
		i++;
		n--;
	}
	return (0);
}
/* int	main(void)
{
	const char	s1[] = "Ananas";
	const char	s2[] = "Ananasinha";
	size_t n;

	n = 10;
	printf("%d\n",ft_strncmp(s1, s2, n)); 
	printf("%d\n",ft_strncmp("test\200", "test\0", 6));
	printf("%d", strncmp("test\200", "test\0", 6));
	printf("%d", strncmp(s1, s2, n));
	return (0);
} */
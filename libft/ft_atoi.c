/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:31:33 by insoares          #+#    #+#             */
/*   Updated: 2024/04/19 10:39:27 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <stdlib.h> */

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	s;
	unsigned int	n;

	i = 0;
	n = 0;
	s = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = s * -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * s);
}
/* int	main(void)
{
	char	str[] = "+-54";
	
	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	return (0);
} */

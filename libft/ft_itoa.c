/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:43:15 by insoares          #+#    #+#             */
/*   Updated: 2024/04/22 15:42:49 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	n_size;
	size_t	i;
	long	nup;

	nup = n;
	n_size = ft_nbrlen(n);
	str = malloc(sizeof(char) * (n_size + 1));
	if (!str)
		return (NULL);
	str[n_size] = '\0';
	i = 0;
	if (nup < 0)
	{
		str[0] = '-';
		nup = nup * -1;
		i = i + 1;
	}
	while (i < n_size)
	{
		str[n_size - 1] = ((nup % 10) + 48);
		nup = nup / 10;
		n_size--;
	}
	return (str);
}
/* int	main(void)
{
	printf("%s", ft_itoa(1234));
	return (0);
} */
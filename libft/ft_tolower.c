/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:31:23 by insoares          #+#    #+#             */
/*   Updated: 2024/04/17 10:38:10 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

int	ft_tolower(int c)
{
	int	d;

	if (c > 64 && c < 91)
	{
		d = c + 32;
		return (d);
	}
	else
		return (c);
}
/* int	main(void)
{
	int	c;

	c = 'I';
	printf("%c", ft_tolower(c));
	return (0);
} */
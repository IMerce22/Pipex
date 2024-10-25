/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:14:32 by insoares          #+#    #+#             */
/*   Updated: 2024/04/17 10:30:48 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

int	ft_toupper(int c)
{
	int	d;

	if (c > 96 && c < 123)
	{
		d = c - 32;
		return (d);
	}
	else
		return (c);
}
/* int main(void)
{
	int	c;

	c = '!';
	printf("%c", ft_toupper(c)); 
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:44:05 by dalexand          #+#    #+#             */
/*   Updated: 2016/02/24 12:05:26 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		u;
	size_t		y;
	size_t		z;

	i = 0;
	u = 0;
	y = 0;
	z = 0;
	while (dst[u] != '\0')
		u++;
	while (src[i] != '\0')
		i++;
	if (u > size)
		return (u + i - (u - size));
	y = u;
	while (src[z] != '\0' && ((y + 1) < size))
	{
		dst[y] = src[z];
		y++;
		z++;
	}
	dst[y] = '\0';
	return (u + i);
}

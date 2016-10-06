/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:40:11 by dalexand          #+#    #+#             */
/*   Updated: 2016/04/12 12:42:47 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	size_t		i;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && l)
	{
		i = 0;
		if (*big == *little)
			while (big[i] == little[i] && big[i] && little[i] && i < l)
				i++;
		if (little[i] == '\0')
			return ((char *)big);
		big++;
		l--;
	}
	return (NULL);
}

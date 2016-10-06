/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:22:52 by dalexand          #+#    #+#             */
/*   Updated: 2016/04/12 12:43:40 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		i = 0;
		if (*big == *little)
			while (big[i] == little[i] && big[i] && little[i])
				i++;
		if (little[i] == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}

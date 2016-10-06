/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:13 by dalexand          #+#    #+#             */
/*   Updated: 2016/02/26 17:15:51 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*str;

	if (!(str = (void *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}

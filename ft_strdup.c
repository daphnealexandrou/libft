/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:12:52 by dalexand          #+#    #+#             */
/*   Updated: 2016/04/07 18:14:27 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ft_strcpy(result, s);
	return (result);
}

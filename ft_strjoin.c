/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:29:52 by dalexand          #+#    #+#             */
/*   Updated: 2016/05/26 16:43:42 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	new = ft_strcpy(new, s1);
	new = ft_strcat(new, s2);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <dalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 20:05:47 by dalexand          #+#    #+#             */
/*   Updated: 2016/04/14 11:31:28 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		begin;
	int		end;
	char	temp;

	i = 0;
	begin = 0;
	while (str[i] != '\0')
		i++;
	end = i - 1;
	while (begin < i / 2)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
	return (str);
}

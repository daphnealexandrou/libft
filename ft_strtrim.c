/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:43:50 by dalexand          #+#    #+#             */
/*   Updated: 2016/02/27 18:47:09 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int begin;
	int end;

	begin = 0;
	while (s[begin] && ft_iswhitespace(s[begin]))
		begin++;
	end = begin;
	while (s[end])
		end++;
	end--;
	while (end > begin && ft_iswhitespace(s[end]))
		end--;
	return (ft_strsub(s, begin, end - begin + 1));
}

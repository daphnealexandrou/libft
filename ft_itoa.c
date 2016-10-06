/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:37:17 by dalexand          #+#    #+#             */
/*   Updated: 2016/04/14 11:30:23 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ltoa(long l, char *s)
{
	if (l == 0)
		return (s);
	s = ft_ltoa(l / 10, s);
	*s = '0' + (l % 10);
	return (s + 1);
}

static int		itoa_len(int nb)
{
	int		i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char	*s;
	char	*result;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = itoa_len(n);
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (0);
	result = s;
	if (n <= 0)
	{
		if ((n = (n < 0) ? -n : n))
			*s = '-';
		if (n == 0)
			*s = '0';
		s++;
	}
	s = ft_ltoa(n, s);
	*s = '\0';
	return (result);
}

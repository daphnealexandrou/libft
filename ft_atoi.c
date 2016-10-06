/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:58:48 by dalexand          #+#    #+#             */
/*   Updated: 2016/02/26 13:37:48 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		negative;
	int		nbr;

	i = 0;
	negative = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ((str[i] >= '0') && (str[i] <= '9')))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * negative);
}

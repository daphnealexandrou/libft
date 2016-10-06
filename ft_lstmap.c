/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:19:17 by dalexand          #+#    #+#             */
/*   Updated: 2016/02/26 18:40:24 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = NULL;
	if (lst)
	{
		one = f(lst);
		one = ft_lstnew(one->content, one->content_size);
		if (!one)
			return (NULL);
		lst = lst->next;
	}
	two = one;
	while (lst)
	{
		three = two;
		two = f(lst);
		two = ft_lstnew(two->content, two->content_size);
		if (!two)
			return (NULL);
		three->next = two;
		lst = lst->next;
	}
	return (one);
}

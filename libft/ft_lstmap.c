/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:33:37 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	if (lst)
	{
		ret = ft_lstnew(f(lst->content));
		if (!ret)
			return (NULL);
		lst = lst->next;
	}
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, tmp);
		lst = lst->next;
	}
	return (ret);
}

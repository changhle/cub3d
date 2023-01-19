/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:21:53 by ljeongin          #+#    #+#             */
/*   Updated: 2022/01/11 12:24:32 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*index;

	if (!lst)
		return ;
	index = *lst;
	while (*lst)
	{
		index = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = index;
	}
	*lst = NULL;
}

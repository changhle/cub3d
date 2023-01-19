/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:03:49 by ljeongin          #+#    #+#             */
/*   Updated: 2021/10/23 12:03:51 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s);
	tmp = 0;
	while (len-- >= 0)
	{
		if (*s == (char)c)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}

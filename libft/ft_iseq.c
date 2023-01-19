/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iseq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:31:03 by ljeongin          #+#    #+#             */
/*   Updated: 2022/08/04 14:34:29 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iseq(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*(s1++) != *(s2++))
			return (0);
	}
	return (*s2 == '\0');
}

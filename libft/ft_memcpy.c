/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:38:08 by ljeongin          #+#    #+#             */
/*   Updated: 2021/12/12 19:41:02 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (dest == src || !n)
		return (dest);
	tmp = dest;
	while (n--)
	{
		*(unsigned char *)dest = *(const unsigned char *)src;
		dest++;
		src++;
	}
	return (tmp);
}

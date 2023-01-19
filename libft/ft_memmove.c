/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:00:44 by ljeongin          #+#    #+#             */
/*   Updated: 2021/12/12 20:58:27 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (dest == src || !n)
		return (dest);
	tmp = (unsigned char *)dest;
	if (dest > src)
	{
		while (n--)
		{
			*((unsigned char *)dest + n) = *((const unsigned char *)src + n);
		}
	}
	else
	{
		while (n--)
		{
			*(unsigned char *)dest = *(const unsigned char *)src;
			dest++;
			src++;
		}
	}
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:00:44 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr       */
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

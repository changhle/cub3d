/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:42:03 by ljeongin          #+#    #+#             */
/*   Updated: 2021/12/21 18:27:28 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;

	dstlen = ft_strlen(dst);
	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}

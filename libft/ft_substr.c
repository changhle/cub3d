/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 03:22:51 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s || !len || !(start < ft_strlen(s)))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	ret = ft_malloc(len + 1, sizeof(char));
	i = 0;
	while (i < len)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 23:37:18 by ljeongin          #+#    #+#             */
/*   Updated: 2022/10/13 09:59:48 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*ret;
	size_t		len;

	len = ft_strlen(s);
	ret = ft_malloc(len + 1, sizeof(char));
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}

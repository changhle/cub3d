/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:56:14 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	size_t			len;
	size_t			i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_len(n);
	i = len;
	ret = ft_malloc(len + 1, sizeof(char));
	if (n < 0)
	{
		n *= -1;
		ret[0] = '-';
		len--;
	}
	ret[i] = '\0';
	while (len-- > 0)
	{
		i--;
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}

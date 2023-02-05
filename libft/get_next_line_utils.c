/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:47:42 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	int	len;

	len = gnl_strlen(s);
	while (len-- > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	char	*ret;
	size_t	len;
	size_t	i;

	i = 0;
	len = gnl_strlen(s);
	ret = ft_malloc(len + 1, sizeof(char));
	while (s[i] && i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s || !len || !(start < gnl_strlen(s)))
		return (gnl_strdup(""));
	if (gnl_strlen(s) + 1 < len)
		len = gnl_strlen(s) - start - 1;
	ret = ft_malloc(len + 1, sizeof(char));
	i = 0;
	while (i < len)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

char	*gnl_strjoin(char *line, char *buf)
{
	size_t	len;
	char	*ret;
	char	*ret_addr;
	char	*line_addr;

	if (!line || !buf)
		return (NULL);
	len = gnl_strlen(line) + gnl_strlen(buf);
	ret = ft_malloc(len + 1, sizeof(char));
	ret_addr = ret;
	line_addr = line;
	while (*line)
		*(ret++) = *(line++);
	while (*buf)
		*(ret++) = *(buf++);
	*ret = '\0';
	ft_free((void **)&line_addr);
	return (ret_addr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 00:33:52 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c, int *count)
{
	int	i;

	*count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			(*count)++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (*count);
}

static char	**free_ret(char **ret, int i)
{
	while (i >= 0)
	{
		free (ret[i]);
		ret[i] = NULL;
		i--;
	}
	free (ret);
	ret = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		count;
	int		words_index;
	int		len_of_word;

	words_index = 0;
	if (!s)
		return (NULL);
	ret = ft_malloc(count_words(s, c, &count) + 1, sizeof(char *));
	while (words_index < count)
	{
		len_of_word = 0;
		while (*s == c)
			s++;
		while (s[len_of_word] != c && s[len_of_word])
			len_of_word++;
		ret[words_index++] = ft_substr(s, 0, len_of_word);
		if (!ret[words_index - 1])
			return (free_ret(ret, words_index - 2));
		s += len_of_word;
	}
	ret[words_index] = NULL;
	return (ret);
}

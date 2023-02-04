/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:56:46 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:56:47 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#include "libft.h"

void	init_buffer(t_buffer *buffer)
{
	buffer->buf = ft_malloc(1 << 4, sizeof(char *));
	buffer->size = 0;
	buffer->cap = 1 << 4;
}

void	append_buffer(t_buffer *buffer, char *str)
{
	char	**temp;

	if (buffer->size >= buffer->cap)
	{
		temp = ft_malloc(buffer->cap << 1, sizeof(char *));
		ft_memcpy(temp, buffer->buf, buffer->size * sizeof(char *));
		ft_free((void **)&buffer->buf);
		buffer->buf = temp;
		buffer->cap <<= 1;
	}
	buffer->buf[buffer->size++] = str;
}

void	clear_buffer(t_buffer *buffer)
{
	while (buffer->size--)
		ft_free((void **)&buffer->buf[buffer->size]);
	ft_free((void **)&buffer->buf);
}

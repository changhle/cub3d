/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:55:53 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 15:51:11 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parse.h"

#include "libft.h"

static void	get_map_size(t_buffer *buffer, t_coord *coord)
{
	size_t	i;
	size_t	max;
	size_t	len;

	max = 0;
	i = 0;
	while (i < buffer->size && buffer->buf[i])
	{
		len = ft_strlen(buffer->buf[i]);
		if (buffer->buf[i][len - 1] == '\n')
			len -= 1;
		if (max < len)
			max = len;
		i++;
	}
	coord->width = max;
	coord->height = i;
}

static t_maparr	get_maparr(char c)
{
	if (c == '0')
		return (FIELD);
	if (c == '1')
		return (WALL);
	if (c == 'N')
		return (POS_N);
	if (c == 'E')
		return (POS_E);
	if (c == 'W')
		return (POS_W);
	if (c == 'S')
		return (POS_S);
	if (c == 'D')
		return (DOOR_C);
	if (c == 'A')
		return (SPRITE);
	if (c == '\n' || c == ' ' || c == '\0')
		return (0);
	error_exit_with_str("mapfile: map: has invalid character");
	return (0);
}

static void	copy_one_line(t_coord *coord, t_buffer *buffer, size_t cur)
{
	size_t	i;
	size_t	len;

	coord->maparr[cur] = ft_malloc(coord->width, sizeof(t_maparr));
	i = 0;
	len = ft_strlen(buffer->buf[cur]);
	while (i < coord->width)
	{
		if (i > len)
			coord->maparr[cur][i] = 0;
		else
			coord->maparr[cur][i] = get_maparr(buffer->buf[cur][i]);
		i++;
	}
}

void	copy_map_from_buf(t_buffer *buffer, t_coord *coord)
{
	size_t	i;

	i = 0;
	get_map_size(buffer, coord);
	coord->maparr = ft_malloc(coord->height, sizeof(t_maparr *));
	while (i < coord->height)
	{
		copy_one_line(coord, buffer, i);
		i++;
	}
}

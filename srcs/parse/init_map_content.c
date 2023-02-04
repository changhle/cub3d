/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:56:17 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:56:17 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parse.h"

#include "libft.h"
#include "get_next_line.h"

static char	*trim_newline_before_map(int fd)
{
	char	*str;

	while (42)
	{
		str = get_next_line(fd);
		if (!str)
			error_exit_with_str("mapfile: map: does not exist");
		if (str[0] != '\n')
			return (str);
		ft_free((void **)&str);
	}
}

static void	check_remain(int fd)
{
	char	*str;

	while (42)
	{
		str = get_next_line(fd);
		if (!str)
			return ;
		if (str[0] != '\n')
			error_exit_with_str("mapfile: map: cannot have empty newline");
		ft_free((void **)&str);
	}
}

static void	get_map_into_buf(int fd, t_buffer *buffer)
{
	char	*str;

	str = trim_newline_before_map(fd);
	while (str && str[0] != '\n')
	{
		append_buffer(buffer, str);
		str = get_next_line(fd);
	}
	if (!str)
		return ;
	ft_free((void **)&str);
	check_remain(fd);
}

void	init_map_content(int fd, t_map *map)
{
	t_buffer	buffer;

	init_buffer(&buffer);
	get_map_into_buf(fd, &buffer);
	copy_map_from_buf(&buffer, map->coord);
	clear_buffer(&buffer);
	check_map(map->coord);
}

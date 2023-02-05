/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:56:40 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 14:12:30 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "parse.h"

#include "libft.h"
#include <fcntl.h>
#include <math.h>

static void	init_t_map(t_game_data *game_data)
{
	game_data->map->texture = ft_malloc(1, sizeof(t_texture));
	game_data->map->texture->n = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->e = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->w = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->s = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->d = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->s_1 = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->s_2 = ft_malloc(1, sizeof(t_image));
	game_data->map->coord = ft_malloc(1, sizeof(t_coord));
}

static int	open_mapfile(const char *filename)
{
	const size_t	len = ft_strlen(filename);
	int				ret;

	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 5))
		error_exit_with_str("mapfile: is invalid filename");
	ret = open(filename, O_RDONLY);
	if (ret == -1)
		perror_exit((char *)filename);
	return (ret);
}

int sprite_cnt(t_map *map)
{
	size_t x;
	size_t y;
	size_t	ret;

	y = 0;
	ret = 0;
	while (y < map->coord->height)
	{
		x = 0;
		while (x < map->coord->width)
		{
			if (map->coord->maparr[y][x] == SPRITE)
				ret++;
			x++;
		}
		y++;
	}
	return (ret);
}

static void	init_sprite(t_game_data *game_data)
{
	size_t	sprite_size;
	int flag;
	int i;
	size_t x;
	size_t y;

	y = 0;
	sprite_size = sprite_cnt(game_data->map);
	flag = 0;
	if (sprite_size == 0)
	{
		sprite_size = 1;
		flag = 1;
	}
	game_data->sprite = ft_malloc(sprite_size, sizeof(t_sprite));
	if (flag)
	{
		game_data->sprite->sprite_size = 0;
		return ;
	}
	game_data->sprite->sprite_size = sprite_size;
	i = 0;
	while (y < game_data->map->coord->height)
	{
		x = 0;
		while (x < game_data->map->coord->width)
		{
			if (game_data->map->coord->maparr[y][x] == SPRITE)
			{
				game_data->sprite[i].x = x + 0.5;
				game_data->sprite[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

// static void	init_sprite(t_game_data *game_data)
// {
// 	int	i;

// 	game_data->sprite = ft_malloc(SPRITE_NUM, sizeof(t_sprite));
// 	i = 0;
// 	while (i < SPRITE_NUM)
// 	{
// 		game_data->sprite[i].y = floor((i * 25) / 65) + 0.5;
// 		game_data->sprite[i].x = floor((i * 25) % 65) + 0.5;
// 		i++;
// 	}
// }

void	parse(const char *argv, t_game_data *game_data)
{
	const int	map_fd = open_mapfile(argv);

	init_t_map(game_data);
	init_texture(map_fd, game_data);
	init_map_content(map_fd, game_data->map);
	ft_close(map_fd);
	init_sprite(game_data);
	init_coord_value(game_data->map->coord);
}

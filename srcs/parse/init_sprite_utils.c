/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:56:40 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:04:05 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

int	sprite_cnt(t_map *map)
{
	size_t	x;
	size_t	y;
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

void	init_sprite_map(t_game_data *game_data)
{
	size_t	x;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
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

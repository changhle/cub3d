/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:55:15 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:05:54 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

void	move_sprite(t_game_data *game_data)
{
	static int	count = 0;

	count++;
	if (count == 20)
	{
		game_data->map->texture->sp = game_data->map->texture->s_2;
		draw_screen(game_data);
	}
	else if (count == 40)
	{
		game_data->map->texture->sp = game_data->map->texture->s_1;
		draw_screen(game_data);
		count = 0;
	}
}

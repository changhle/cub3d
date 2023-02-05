/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:55:15 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:43:19 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

void	move_sprite(t_game_data *game_data)
{
	static int	count = 0;

	count++;
	if (count == 20)
		game_data->map->texture->sp = game_data->map->texture->s_2;
	else if (count == 40)
	{
		game_data->map->texture->sp = game_data->map->texture->s_1;
		count = 0;
	}
}

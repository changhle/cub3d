/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:54:50 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:54:51 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

static int	is_set(int engine, enum e_dir dir)
{
	return ((engine & dir) != 0);
}

static int	get_direction(int lhs, int rhs)
{
	return (lhs - rhs);
}

int	move_engine(t_game_data *game_data)
{
	const int	vertical_dir
		= get_direction(is_set(game_data->engine, DIR_W),
			is_set(game_data->engine, DIR_S));
	const int	horizonal_dir
		= get_direction(is_set(game_data->engine, DIR_A),
			is_set(game_data->engine, DIR_D));
	const int	rotate_dir
		= get_direction(is_set(game_data->engine, ROT_LEFT),
			is_set(game_data->engine, ROT_RIGHT));

	if (horizonal_dir > 0)
		move_left(game_data->map->coord);
	else if (horizonal_dir < 0)
		move_right(game_data->map->coord);
	if (vertical_dir > 0)
		move_forward(game_data->map->coord);
	else if (vertical_dir < 0)
		move_backward(game_data->map->coord);
	if (rotate_dir > 0)
		rotate_left(game_data->map->coord);
	else if (rotate_dir < 0)
		rotate_right(game_data->map->coord);
	return (0);
}

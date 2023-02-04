/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:54:42 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:54:43 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

static int	door_no(t_coord *coord)
{
	int	door;
	int	x;
	int	y;

	door = TRUE;
	x = (int)coord->pos_x;
	y = (int)coord->pos_y;
	if (coord->dir_y > 0.9 && coord->maparr[y + 1][x] == DOOR_C)
		coord->maparr[y + 1][x] = DOOR_O;
	else if (coord->dir_y > 0.9 && coord->maparr[y + 1][x] == DOOR_O)
		coord->maparr[y + 1][x] = DOOR_C;
	else if (coord->dir_y > 0.9 && coord->maparr[y + 2][x] == DOOR_C)
		coord->maparr[y + 2][x] = DOOR_O;
	else if (coord->dir_y > 0.9 && coord->maparr[y + 2][x] == DOOR_O)
		coord->maparr[y + 2][x] = DOOR_C;
	else
		door = FALSE;
	return (door);
}

static int	door_so(t_coord *coord)
{
	int	door;
	int	x;
	int	y;

	door = TRUE;
	x = (int)coord->pos_x;
	y = (int)coord->pos_y;
	if (coord->dir_y < -0.9 && coord->maparr[y - 1][x] == DOOR_C)
		coord->maparr[y - 1][x] = DOOR_O;
	else if (coord->dir_y < -0.9 && coord->maparr[y - 1][x] == DOOR_O)
		coord->maparr[y - 1][x] = DOOR_C;
	else if (coord->dir_y < -0.9 && coord->maparr[y - 2][x] == DOOR_C)
		coord->maparr[y - 2][x] = DOOR_O;
	else if (coord->dir_y < -0.9 && coord->maparr[y - 2][x] == DOOR_O)
		coord->maparr[y - 2][x] = DOOR_C;
	else
		door = FALSE;
	return (door);
}

static int	door_ea(t_coord *coord)
{
	int	door;
	int	x;
	int	y;

	door = TRUE;
	x = (int)coord->pos_x;
	y = (int)coord->pos_y;
	if (coord->dir_x > 0.9 && coord->maparr[y][x + 1] == DOOR_C)
		coord->maparr[y][x + 1] = DOOR_O;
	else if (coord->dir_x > 0.9 && coord->maparr[y][x + 1] == DOOR_O)
		coord->maparr[y][x + 1] = DOOR_C;
	else if (coord->dir_x > 0.9 && coord->maparr[y][x + 2] == DOOR_C)
		coord->maparr[y][x + 2] = DOOR_O;
	else if (coord->dir_x > 0.9 && coord->maparr[y][x + 2] == DOOR_O)
		coord->maparr[y][x + 2] = DOOR_C;
	else
		door = FALSE;
	return (door);
}

static int	door_we(t_coord *coord)
{
	int	door;
	int	x;
	int	y;

	door = TRUE;
	x = (int)coord->pos_x;
	y = (int)coord->pos_y;
	if (coord->dir_x < -0.9 && coord->maparr[y][x - 1] == DOOR_C)
		coord->maparr[y][x - 1] = DOOR_O;
	else if (coord->dir_x < -0.9 && coord->maparr[y][x - 1] == DOOR_O)
		coord->maparr[y][x - 1] = DOOR_C;
	else if (coord->dir_x < -0.9 && coord->maparr[y][x - 2] == DOOR_C)
		coord->maparr[y][x - 2] = DOOR_O;
	else if (coord->dir_x < -0.9 && coord->maparr[y][x - 2] == DOOR_O)
		coord->maparr[y][x - 2] = DOOR_C;
	else
		door = FALSE;
	return (door);
}

void	move_door(t_game_data *game_date)
{
	if (door_no(game_date->map->coord) || door_so(game_date->map->coord)
		|| door_ea(game_date->map->coord) || door_we(game_date->map->coord))
		game_date->door = TRUE;
	else
		game_date->door = FALSE;
}

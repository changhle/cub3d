/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:55:07 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:55:09 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

void	move_forward(t_coord *coord)
{
	int	adj_x;
	int	adj_y;

	adj_x = (int)(coord->pos_x + coord->dir_x * (coord->move_speed + 0.3));
	adj_y = (int)(coord->pos_y + coord->dir_y * (coord->move_speed + 0.3));
	if (coord->maparr[(int)coord->pos_y][adj_x] != WALL
		&& coord->maparr[(int)coord->pos_y][adj_x] != DOOR_C)
		coord->pos_x += coord->dir_x * coord->move_speed;
	if (coord->maparr[(int)(adj_y)][(int)coord->pos_x] != WALL
		&& coord->maparr[(int)(adj_y)][(int)coord->pos_x] != DOOR_C)
		coord->pos_y += coord->dir_y * coord->move_speed;
}

void	move_backward(t_coord *coord)
{
	int	adj_x;
	int	adj_y;

	adj_x = (int)(coord->pos_x - coord->dir_x * (coord->move_speed + 0.3));
	adj_y = (int)(coord->pos_y - coord->dir_y * (coord->move_speed + 0.3));
	if (coord->maparr[(int)coord->pos_y][adj_x] != WALL
		&& coord->maparr[(int)coord->pos_y][adj_x] != DOOR_C)
		coord->pos_x -= coord->dir_x * coord->move_speed;
	if (coord->maparr[(int)(adj_y)][(int)coord->pos_x] != WALL
		&& coord->maparr[(int)(adj_y)][(int)coord->pos_x] != DOOR_C)
		coord->pos_y -= coord->dir_y * coord->move_speed;
}

void	move_right(t_coord *coord)
{
	int	adj_x;
	int	adj_y;

	adj_x = (int)(
			coord->pos_x + (coord->plane_x / 0.66) * (coord->move_speed + 0.3)
			);
	adj_y = (int)(
			coord->pos_y + (coord->plane_y / 0.66) * (coord->move_speed + 0.3)
			);
	if (coord->maparr[(int)coord->pos_y][adj_x] != WALL
		&& coord->maparr[(int)coord->pos_y][adj_x] != DOOR_C)
		coord->pos_x += (coord->plane_x / 0.66) * coord->move_speed;
	if (coord->maparr[adj_y][(int)coord->pos_x] != WALL
		&& coord->maparr[adj_y][(int)coord->pos_x] != DOOR_C)
		coord->pos_y += (coord->plane_y / 0.66) * coord->move_speed;
}

void	move_left(t_coord *coord)
{
	int	adj_x;
	int	adj_y;

	adj_x = (int)(
			coord->pos_x - (coord->plane_x / 0.66) * (coord->move_speed + 0.3)
			);
	adj_y = (int)(
			coord->pos_y - (coord->plane_y / 0.66) * (coord->move_speed + 0.3)
			);
	if (coord->maparr[(int)coord->pos_y][adj_x] != WALL
		&& coord->maparr[(int)coord->pos_y][adj_x] != DOOR_C)
		coord->pos_x -= (coord->plane_x / 0.66) * coord->move_speed;
	if (coord->maparr[adj_y][(int)coord->pos_x] != WALL
		&& coord->maparr[adj_y][(int)coord->pos_x] != DOOR_C)
		coord->pos_y -= (coord->plane_y / 0.66) * coord->move_speed;
}

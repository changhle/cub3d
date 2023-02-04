/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:56:08 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:56:10 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	get_initial_player_pos(t_coord *coord)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < coord->height)
	{
		x = 0;
		while (x < coord->width)
		{
			if (coord->maparr[y][x] & PLAYER)
			{
				coord->pos_x = (double)x + 0.5;
				coord->pos_y = (double)y + 0.5;
				break ;
			}
			x++;
		}
		y++;
	}
}

static void	get_initial_dir_vec(t_coord *coord)
{
	if (coord->maparr[(int)coord->pos_y][(int)coord->pos_x] == POS_E)
	{
		coord->dir_x = 1;
		coord->dir_y = 0;
	}
	else if (coord->maparr[(int)coord->pos_y][(int)coord->pos_x] == POS_W)
	{
		coord->dir_x = -1;
		coord->dir_y = 0;
	}
	else if (coord->maparr[(int)coord->pos_y][(int)coord->pos_x] == POS_S)
	{
		coord->dir_x = 0;
		coord->dir_y = 1;
	}
	else if (coord->maparr[(int)coord->pos_y][(int)coord->pos_x] == POS_N)
	{
		coord->dir_x = 0;
		coord->dir_y = -1;
	}
	coord->maparr[(int)coord->pos_y][(int)coord->pos_x] = FIELD;
}

static void	get_initial_plane_vec(t_coord *coord)
{
	if (coord->dir_x)
	{
		coord->plane_x = 0;
		if (coord->dir_x > 0)
			coord->plane_y = 0.66;
		else
			coord->plane_y = -0.66;
	}
	else if (coord->dir_y)
	{
		if (coord->dir_y > 0)
			coord->plane_x = -0.66;
		else
			coord->plane_x = 0.66;
		coord->plane_y = 0;
	}
}

void	init_coord_value(t_coord *coord)
{
	get_initial_player_pos(coord);
	get_initial_dir_vec(coord);
	get_initial_plane_vec(coord);
	coord->move_speed = 0.05;
	coord->rot_speed = 0.03;
}

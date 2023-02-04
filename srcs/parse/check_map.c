/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:55:45 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:55:46 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parse.h"

static int	set_door(t_coord *coord, size_t x, size_t y)
{
	if ((coord->maparr[y][x - 1] == WALL && coord->maparr[y][x + 1] == WALL
		&& coord->maparr[y - 1][x] == FIELD && coord->maparr[y + 1][x] == FIELD)
		|| (coord->maparr[y - 1][x] == WALL && coord->maparr[y + 1][x] == WALL
		&& coord->maparr[y][x - 1] == FIELD && coord->maparr[y][x + 1] == FIELD)
		)
		return (TRUE);
	return (FALSE);
}

void	check_map(t_coord *coord)
{
	size_t	x;
	size_t	y;
	size_t	player_cnt;

	y = 0;
	player_cnt = 0;
	while (y < coord->height)
	{
		x = 0;
		while (x < coord->width)
		{
			if (coord->maparr[y][x] & PLAYER)
				player_cnt++;
			if (coord->maparr[y][x] & DOOR_C && !set_door(coord, x, y))
				return (error_exit_with_str("map: door parsing error"));
			x++;
		}
		y++;
	}
	if (player_cnt == 0)
		error_exit_with_str("map: does not have player spawn");
	if (player_cnt > 1)
		error_exit_with_str("map: has too many player spawn");
	check_horizontal_line(coord->width, coord->height, coord->maparr);
	check_vertical_line(coord->width, coord->height, coord->maparr);
}

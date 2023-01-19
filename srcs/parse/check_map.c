/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:12:26 by ljeongin          #+#    #+#             */
/*   Updated: 2022/11/17 10:51:51 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parse.h"

static size_t	check_vertical_part(
	size_t height, size_t start, t_maparr **maparr, size_t x
	)
{
	size_t	i;
	size_t	end;

	if (maparr[start][x] != WALL)
		error_exit_with_str("map: is not surrounded by walls");
	i = start;
	while (i < height && maparr[i][x])
	{
		end = i;
		i++;
	}
	if (maparr[end][x] != WALL)
		error_exit_with_str("map: is not surrounded by walls");
	return (end - start + 1);
}

static void	check_vertical_line(size_t width, size_t height, t_maparr **maparr)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			while (y < height && !maparr[y][x])
				y++;
			if (y < height && maparr[y][x])
				y += check_vertical_part(height, y, maparr, x);
		}
		x++;
	}
}

static size_t	check_horizontal_part(
	size_t width, size_t start, t_maparr **maparr, size_t y
	)
{
	size_t	i;
	size_t	end;

	if (maparr[y][start] != WALL)
		error_exit_with_str("map: is not surrounded by walls");
	i = start;
	while (i < width && maparr[y][i])
	{
		end = i;
		i++;
	}
	if (maparr[y][end] != WALL)
		error_exit_with_str("map: is not surrounded by walls");
	return (end - start + 1);
}

static void	check_horizontal_line(
	size_t width, size_t height, t_maparr **maparr
	)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			while (x < width && !maparr[y][x])
				x++;
			if (x < width && maparr[y][x])
				x += check_horizontal_part(width, x, maparr, y);
		}
		y++;
	}
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

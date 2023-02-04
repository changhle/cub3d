/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:55:36 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:55:38 by changhle         ###   ########.fr       */
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

void	check_vertical_line(size_t width, size_t height, t_maparr **maparr)
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

void	check_horizontal_line(size_t width, size_t height, t_maparr **maparr)
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

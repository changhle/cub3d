/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:54:59 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:55:00 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

#include "macro.h"
#include "mlx.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	set_dir(int n)
{
	if (n < 0)
		return (LEFT);
	else
		return (RIGHT);
}

void	move_mouse(t_game_data *game_data)
{
	int	x;
	int	y;
	int	abs_x;
	int	dir;

	mlx_mouse_get_pos(game_data->mlx->win_ptr, &x, &y);
	abs_x = ft_abs(x - game_data->x);
	dir = set_dir(x - game_data->x);
	if (abs_x >= 1)
	{
		mlx_mouse_move(game_data->mlx->win_ptr,
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		while (abs_x > 0)
		{
			if (dir == LEFT)
				rotate_left(game_data->map->coord);
			else
				rotate_right(game_data->map->coord);
			abs_x -= 5;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:58 by ljeongin          #+#    #+#             */
/*   Updated: 2023/02/03 13:30:50 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

#include "libft.h"
#include "macro.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

int	mlx_loop_hook_event(t_game_data *game_data)
{
	if (!game_data->engine && game_data->mouse == -1
		&& game_data->door == FALSE)
		return (1);
	else if (game_data->mouse == 1)
		move_mouse(game_data);
	move_engine(game_data);
	draw_screen(game_data);
	draw_minimap(game_data, game_data->mlx->minimap);
	return (0);
}

static void	mlx_mouse_event(t_game_data *game_data)
{
	game_data->mouse *= -1;
	if (game_data->mouse == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_move(game_data->mlx->win_ptr,
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		mlx_mouse_get_pos(game_data->mlx->win_ptr,
			&game_data->x, &game_data->y);
	}
	else
		mlx_mouse_show();
}

int	mlx_key_press_event(int keycode, t_game_data *game_data)
{
	if (keycode == ESC)
		exit_event(NULL);
	if (keycode == W || keycode == UP)
		game_data->engine |= DIR_W;
	if (keycode == A)
		game_data->engine |= DIR_A;
	if (keycode == S || keycode == DOWN)
		game_data->engine |= DIR_S;
	if (keycode == D)
		game_data->engine |= DIR_D;
	if (keycode == E)
		game_data->door = move_door(game_data->map->coord);
	if (keycode == LEFT)
		game_data->engine |= ROT_LEFT;
	if (keycode == RIGHT)
		game_data->engine |= ROT_RIGHT;
	if (keycode == ONE)
		mlx_mouse_event(game_data);
	return (0);
}

int	mlx_key_release_event(int keycode, t_game_data *game_data)
{
	if (keycode == W || keycode == UP)
		game_data->engine &= ~DIR_W;
	if (keycode == A)
		game_data->engine &= ~DIR_A;
	if (keycode == S || keycode == DOWN)
		game_data->engine &= ~DIR_S;
	if (keycode == D)
		game_data->engine &= ~DIR_D;
	if (keycode == LEFT)
		game_data->engine &= ~ROT_LEFT;
	if (keycode == RIGHT)
		game_data->engine &= ~ROT_RIGHT;
	return (0);
}

int	exit_event(void *game_data)
{
	(void) game_data;
	ft_putstr_fd("Bye!\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}

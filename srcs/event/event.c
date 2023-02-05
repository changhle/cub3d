/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:54:30 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:53:25 by changhle         ###   ########.fr       */
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
		&& game_data->door == FALSE && !game_data->sprite->sprite_size)
		return (1);
	if (game_data->mouse == 1)
		move_mouse(game_data);
	move_engine(game_data);
	move_sprite(game_data);
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
		move_door(game_data);
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

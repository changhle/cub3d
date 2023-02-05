/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:57:42 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 16:15:00 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "libft.h"
#include <math.h>
#include <stdlib.h>

static void	transform_sprite(t_coord *coord, t_sprite *sprite)
{
	sprite->inv_det = 1.0 / (coord->plane_x * coord->dir_y
			- coord->dir_x * coord->plane_y);
	sprite->transform_x = sprite->inv_det * (coord->dir_y * sprite->sprite_x
			- coord->dir_x * sprite->sprite_y);
	sprite->transform_y = sprite->inv_det * (-coord->plane_y * sprite->sprite_x
			+ coord->plane_x * sprite->sprite_y);
	sprite->sprite_screen_x = (int)((SCREEN_WIDTH / 2)
			* (1 + sprite->transform_x / sprite->transform_y));
}

static void	calculate_sprite(t_sprite *sprite)
{
	int	v_move_screen;

	v_move_screen = (int)(VMOVE / sprite->transform_y);
	sprite->sprite_width = \
		abs((int)(SCREEN_HEIGHT / sprite->transform_y) / U_DIV);
	sprite->draw_start_x = -sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_end_x >= SCREEN_WIDTH)
		sprite->draw_end_x = SCREEN_WIDTH - 1;
	sprite->sprite_height = \
		abs((int)(SCREEN_HEIGHT / sprite->transform_y) / V_DIV);
	sprite->draw_start_y = -sprite->sprite_height / 2 + SCREEN_HEIGHT / 2
		+ v_move_screen;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->sprite_height / 2 + SCREEN_HEIGHT / 2
		+ v_move_screen;
	if (sprite->draw_end_y >= SCREEN_HEIGHT)
		sprite->draw_end_y = SCREEN_HEIGHT - 1;
}

static void	stripe_of_sprite(t_game_data *game_data, t_sprite *sprite,
	double z_buffer[])
{
	int	stripe;

	stripe = sprite->draw_start_x;
	while (stripe < sprite->draw_end_x)
	{
		sprite->texture_x = (int)(256 * (stripe - (-sprite->sprite_width / 2
						+ sprite->sprite_screen_x))
				* TEXTURE_WIDTH / sprite->sprite_width) / 256;
		if (sprite->transform_y > 0 && stripe > 0 && stripe < SCREEN_WIDTH
			&& sprite->transform_y < z_buffer[stripe])
			draw_sprite(game_data, sprite, stripe);
		stripe++;
	}
}

static void	init_sprite_cast(double **sprite_distance, int **sprite_order,
	t_sprite *sprite, t_coord *coord)
{
	size_t	i;

	i = 0;
	*sprite_distance = ft_malloc(sprite->sprite_size, sizeof(double *));
	*sprite_order = ft_malloc(sprite->sprite_size, sizeof(int *));
	while (i < sprite->sprite_size)
	{
		(*sprite_order)[i] = i;
		(*sprite_distance)[i] = pow(coord->pos_x - sprite[i].x, 2)
			+ pow(coord->pos_y - sprite[i].y, 2);
		i++;
	}
}

void	sprite_cast(t_game_data *game_data, t_coord *coord, t_sprite *sprite,
	double z_buffer[])
{
	size_t	i;
	double	*sprite_distance;
	int		*sprite_order;

	i = 0;
	if (sprite->sprite_size)
	{
		init_sprite_cast(&sprite_distance, &sprite_order, sprite, coord);
		sort_sprite(sprite_order, sprite_distance, sprite);
		i = 0;
		while (i < sprite->sprite_size)
		{
			sprite->sprite_x = sprite[sprite_order[i]].x - coord->pos_x;
			sprite->sprite_y = sprite[sprite_order[i]].y - coord->pos_y;
			transform_sprite(coord, sprite);
			calculate_sprite(sprite);
			stripe_of_sprite(game_data, sprite, z_buffer);
			i++;
		}
		ft_free((void **)&sprite_distance);
		ft_free((void **)&sprite_order);
	}
}

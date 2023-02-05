/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:57:42 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 14:17:17 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

#include <math.h>
#include <stdlib.h>

// static void	sort_sprite(int order[], double distance[])
// {
// 	int		i;
// 	int		j;
// 	int		tmp_int;
// 	double	tmp_double;

// 	i = SPRITE_NUM - 1;
// 	while (i > 0)
// 	{
// 		j = 0;
// 		while (j < i)
// 		{
// 			if (distance[j] < distance[j + 1])
// 			{
// 				tmp_double = distance[j];
// 				distance[j] = distance[j + 1];
// 				distance[j + 1] = tmp_double;
// 				tmp_int = order[j];
// 				order[j] = order[j + 1];
// 				order[j + 1] = tmp_int;
// 			}
// 			j++;
// 		}
// 		i--;
// 	}
// }
static void	sort_sprite(int order[], double distance[], t_sprite *sprite)
{
	int		i;
	int		j;
	int		tmp_int;
	double	tmp_double;

	i = sprite->sprite_size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (distance[j] < distance[j + 1])
			{
				tmp_double = distance[j];
				distance[j] = distance[j + 1];
				distance[j + 1] = tmp_double;
				tmp_int = order[j];
				order[j] = order[j + 1];
				order[j + 1] = tmp_int;
			}
			j++;
		}
		i--;
	}
}

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
	sprite->sprite_width = abs((int)(SCREEN_HEIGHT / sprite->transform_y));
	sprite->draw_start_x = -sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_end_x >= SCREEN_WIDTH)
		sprite->draw_end_x = SCREEN_WIDTH - 1;
	sprite->sprite_height = abs((int)(SCREEN_HEIGHT / sprite->transform_y));
	sprite->draw_start_y = -sprite->sprite_height / 2 + SCREEN_HEIGHT / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->sprite_height / 2 + SCREEN_HEIGHT / 2;
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

// void	sprite_cast(t_game_data *game_data, t_coord *coord, t_sprite *sprite,
// 	double z_buffer[])
// {
// 	int		i;
// 	int		sprite_order[SPRITE_NUM];
// 	double	sprite_distance[SPRITE_NUM];

// 	i = 0;
// 	while (i < SPRITE_NUM)
// 	{
// 		sprite_order[i] = i;
// 		sprite_distance[i] = pow(coord->pos_x - sprite[i].x, 2)
// 			+ pow(coord->pos_y - sprite[i].y, 2);
// 		i++;
// 	}
// 	sort_sprite(sprite_order, sprite_distance);
// 	i = 0;
// 	while (i < SPRITE_NUM)
// 	{
// 		sprite->sprite_x = sprite[sprite_order[i]].x - coord->pos_x;
// 		sprite->sprite_y = sprite[sprite_order[i]].y - coord->pos_y;
// 		transform_sprite(coord, sprite);
// 		calculate_sprite(sprite);
// 		stripe_of_sprite(game_data, sprite, z_buffer);
// 		i++;
// 	}
// }
void	sprite_cast(t_game_data *game_data, t_coord *coord, t_sprite *sprite,
	double z_buffer[])
{
	size_t		i;
	int		sprite_order[sprite->sprite_size];
	double	sprite_distance[sprite->sprite_size];

	i = 0;
	while (i < sprite->sprite_size)
	{
		sprite_order[i] = i;
		sprite_distance[i] = pow(coord->pos_x - sprite[i].x, 2)
			+ pow(coord->pos_y - sprite[i].y, 2);
		i++;
	}
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
}
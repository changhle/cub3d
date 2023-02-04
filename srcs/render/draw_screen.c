/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:19:31 by ljeongin          #+#    #+#             */
/*   Updated: 2023/02/04 21:11:47 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

#include "mlx.h"

static void	draw_background(t_screen *screen, t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < (SCREEN_HEIGHT / 2))
				screen->addr[screen->sizel / (screen->bpp / 8) * y + x]
					= map->texture->ceil;
			else
				screen->addr[screen->sizel / (screen->bpp / 8) * y + x]
					= map->texture->floor;
			x++;
		}
		y++;
	}
}

static int	get_pixel_color(t_texture *texture, t_wall_dir wall_dir, t_ray *ray)
{
	if (wall_dir == NORTH_WALL)
		return (texture->n->addr[(texture->n->sizel / (texture->n->bpp / 8))
				* ray->texture_y + ray->texture_x]);
	else if (wall_dir == EAST_WALL)
		return (texture->e->addr[(texture->e->sizel / (texture->e->bpp / 8))
				* ray->texture_y + ray->texture_x]);
	else if (wall_dir == WEST_WALL)
		return (texture->w->addr[(texture->w->sizel / (texture->w->bpp / 8))
				* ray->texture_y + ray->texture_x]);
	else if (wall_dir == SOUTH_WALL)
		return (texture->s->addr[(texture->s->sizel / (texture->s->bpp / 8))
				* ray->texture_y + ray->texture_x]);
	else
		return (texture->d->addr[(texture->d->sizel / (texture->d->bpp / 8))
				* ray->texture_y + ray->texture_x]);
}

static void	draw_line_per_x(t_screen *screen, t_map *map, t_ray *ray, size_t x)
{
	int	y;

	y = ray->start_point;
	while (y < ray->end_point)
	{
		ray->texture_y = (int)ray->texture_pos & (TEXTURE_HEIGHT - 1);
		ray->texture_pos += ray->step;
		screen->addr[screen->sizel / (screen->bpp / 8) * y + x]
			= get_pixel_color(map->texture, ray->wall_dir, ray);
		y++;
	}
}

void	draw_sprite(t_game_data *game_data, t_sprite *sprite, size_t x)
{
	int			y;
	t_texture	*texture;
	t_screen	*screen;
	size_t		color;

	texture = game_data->map->texture;
	screen = game_data->mlx->screen;
	y = sprite->draw_start_y;
	while (y < sprite->draw_end_y)
	{
		sprite->texture_y = (((y * 256 - SCREEN_HEIGHT * 128
						+ sprite->sprite_height * 128) * TEXTURE_HEIGHT)
				/ sprite->sprite_height) / 256;
		color = texture->sp->addr[(texture->sp->sizel / (texture->sp->bpp / 8))
			* sprite->texture_y + sprite->texture_x];
		if ((color & 0x00FFFFFF) != 0)
			screen->addr[screen->sizel / (screen->bpp / 8) * y + x] = color;
		y++;
	}
}

void	draw_screen(t_game_data *game_data)
{
	t_ray	ray;
	int		x;
	double	z_buffer[SCREEN_WIDTH];

	mlx_put_image_to_window(
		game_data->mlx->mlx_ptr, game_data->mlx->win_ptr,
		game_data->mlx->screen->img_ptr, 0, 0
		);
	draw_background(game_data->mlx->screen, game_data->map);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		raycast(game_data->map->coord, &ray, x);
		draw_line_per_x(game_data->mlx->screen, game_data->map, &ray, x);
		z_buffer[x] = ray.perp_walldist;
		x++;
	}
	sprite_cast(game_data, game_data->map->coord, game_data->sprite, z_buffer);
}

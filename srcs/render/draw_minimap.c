/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:57:06 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 15:51:18 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "mlx.h"

static int	get_minimap_rgb(t_map *map, size_t x, size_t y, size_t magx)
{
	if (map->coord->maparr[y / magx][x / magx] == WALL)
		return (MINI_WALL);
	else if ((y / magx == (size_t)map->coord->pos_y)
		&& x / magx == (size_t)map->coord->pos_x)
		return (MINI_PLAYER);
	else if (map->coord->maparr[y / magx][x / magx] == DOOR_C
		|| map->coord->maparr[y / magx][x / magx] == DOOR_O)
		return (MINI_DOOR);
	else if (map->coord->maparr[y / magx][x / magx] == SPRITE)
		return (MINI_SPRITE);
	else if (map->coord->maparr[y / magx][x / magx] == FIELD)
		return (MINI_FIELD);
	else
		return (MINI_VOID);
}

void	draw_minimap(t_game_data *game_data, t_minimap *minimap)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y / minimap->magx < game_data->map->coord->height)
	{
		x = 0;
		while (x / minimap->magx < game_data->map->coord->width)
		{
			minimap->addr[minimap->sizel / (minimap->bpp / 8) * y + x]
				= get_minimap_rgb(game_data->map, x, y, minimap->magx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(
		game_data->mlx->mlx_ptr, game_data->mlx->win_ptr, minimap->img_ptr, 0, 0
		);
}

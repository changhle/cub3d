/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:19:36 by ljeongin          #+#    #+#             */
/*   Updated: 2022/11/17 10:53:25 by ljeongin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

#include "mlx.h"

static int	get_minimap_rgb(t_map *map, size_t x, size_t y, size_t magx)
{
	if (map->coord->maparr[y / magx][x / magx] == WALL)
		return (MINI_WALL);
	if ((y / magx == (size_t)map->coord->pos_y)
		&& x / magx == (size_t)map->coord->pos_x)
		return (MINI_PLAYER);
	if (map->coord->maparr[y / magx][x / magx] == FIELD)
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

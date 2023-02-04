/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:57:21 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:57:23 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

#include "mlx.h"
#include "libft.h"

void	error_exit_with_str(char *str);

static void	init_screen(t_mlx *mlx)
{
	mlx->screen = ft_malloc(1, sizeof(t_screen));
	mlx->screen->img_ptr
		= mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->screen->addr
		= (int *)mlx_get_data_addr(
			mlx->screen->img_ptr,
			&mlx->screen->bpp,
			&mlx->screen->sizel,
			&mlx->screen->endian
			);
}

static size_t	get_minimap_magnification(t_coord *coord)
{
	size_t	ret;

	ret = 8;
	while (ret > 0)
	{
		if (coord->width * ret <= SCREEN_WIDTH / 3
			&& coord->height * ret <= SCREEN_HEIGHT / 3)
			return (ret);
		ret--;
	}
	error_exit_with_str("map: is too big");
	return (ret);
}

static void	init_minimap(t_mlx *mlx, t_coord *coord)
{
	mlx->minimap = ft_malloc(1, sizeof(t_minimap));
	mlx->minimap->magx = get_minimap_magnification(coord);
	mlx->minimap->img_ptr
		= mlx_new_image(
			mlx->mlx_ptr,
			coord->width * mlx->minimap->magx,
			coord->height * mlx->minimap->magx
			);
	mlx->minimap->addr
		= (int *)mlx_get_data_addr(
			mlx->minimap->img_ptr,
			&mlx->minimap->bpp,
			&mlx->minimap->sizel,
			&mlx->minimap->endian
			);
}

void	init_mlx(t_game_data *game_data, t_map *map, t_mlx *mlx)
{
	mlx->win_ptr
		= mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	init_screen(mlx);
	init_minimap(mlx, map->coord);
	draw_screen(game_data);
	draw_minimap(game_data, game_data->mlx->minimap);
}

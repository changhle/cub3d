/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:57:29 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:57:30 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "macro.h"

#include <math.h>

static void	init_sidedist_value(t_coord *coord, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (coord->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - coord->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (coord->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - coord->pos_y) * ray->deltadist_y;
	}
}

static void	calculate_sidedist_value(t_coord *coord, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (coord->maparr[ray->map_y][ray->map_x] == WALL
			|| coord->maparr[ray->map_y][ray->map_x] == DOOR_C)
			ray->hit = TRUE;
	}
}

static void	calculate_line_value(t_coord *coord, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_walldist
			= (ray->map_x - coord->pos_x + (1 - ray->step_x) / 2)
			/ ray->raydir_x;
	else
		ray->perp_walldist
			= (ray->map_y - coord->pos_y + (1 - ray->step_y) / 2)
			/ ray->raydir_y;
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_walldist);
	ray->start_point = (SCREEN_HEIGHT / 2) - (ray->line_height / 2);
	if (ray->start_point < 0)
		ray->start_point = 0;
	ray->end_point = (SCREEN_HEIGHT / 2) + (ray->line_height / 2);
	if (ray->end_point >= SCREEN_HEIGHT)
		ray->end_point = SCREEN_HEIGHT - 1;
}

static void	calculate_texture_value(t_coord *coord, t_ray *ray)
{
	if (coord->maparr[ray->map_y][ray->map_x] == DOOR_C)
		ray->wall_dir = DOOR_WALL;
	else if (ray->side && ray->raydir_y > 0)
		ray->wall_dir = NORTH_WALL;
	else if (ray->side && ray->raydir_y < 0)
		ray->wall_dir = SOUTH_WALL;
	else if (!ray->side && ray->raydir_x < 0)
		ray->wall_dir = EAST_WALL;
	else if (!ray->side && ray->raydir_x > 0)
		ray->wall_dir = WEST_WALL;
	if (ray->side)
		ray->wall_x = coord->pos_x + ray->perp_walldist * ray->raydir_x;
	else
		ray->wall_x = coord->pos_y + ray->perp_walldist * ray->raydir_y;
	ray->wall_x -= floor(ray->wall_x);
	ray->texture_x = (int)(ray->wall_x * (double)TEXTURE_WIDTH);
	if ((ray->side && ray->raydir_y < 0) || (!ray->side && ray->raydir_x < 0))
		ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;
	ray->step = (double)TEXTURE_HEIGHT / ray->line_height;
	ray->texture_pos
		= (ray->start_point - SCREEN_HEIGHT / 2 + ray->line_height / 2)
		* ray->step;
}

void	raycast(t_coord *coord, t_ray *ray, size_t x)
{
	ray->hit = FALSE;
	ray->camera_x = (2 * x) / (double)SCREEN_WIDTH - 1;
	ray->raydir_x = coord->dir_x + (coord->plane_x * ray->camera_x);
	ray->raydir_y = coord->dir_y + (coord->plane_y * ray->camera_x);
	ray->map_x = (int)coord->pos_x;
	ray->map_y = (int)coord->pos_y;
	if (ray->raydir_y == 0)
			ray->deltadist_x = 0;
	else if (ray->raydir_x == 0)
		ray->deltadist_x = 1;
	else
		ray->deltadist_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_x == 0)
		ray->deltadist_y = 0;
	else if (ray->raydir_y == 0)
		ray->deltadist_y = 1;
	else
		ray->deltadist_y = fabs(1 / ray->raydir_y);
	init_sidedist_value(coord, ray);
	calculate_sidedist_value(coord, ray);
	calculate_line_value(coord, ray);
	calculate_texture_value(coord, ray);
}

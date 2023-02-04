/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:55:23 by changhle          #+#    #+#             */
/*   Updated: 2023/02/05 06:55:25 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#include <math.h>

void	rotate_right(t_coord *coord)
{
	const double	old_dir_x = coord->dir_x;
	const double	old_plane_x = coord->plane_x;

	coord->dir_x
		= coord->dir_x * cos(coord->rot_speed)
		- coord->dir_y * sin(coord->rot_speed);
	coord->dir_y
		= old_dir_x * sin(coord->rot_speed)
		+ coord->dir_y * cos(coord->rot_speed);
	coord->plane_x
		= coord->plane_x * cos(coord->rot_speed)
		- coord->plane_y * sin(coord->rot_speed);
	coord->plane_y
		= old_plane_x * sin(coord->rot_speed)
		+ coord->plane_y * cos(coord->rot_speed);
}

void	rotate_left(t_coord *coord)
{
	const double	old_dir_x = coord->dir_x;
	const double	old_plane_x = coord->plane_x;

	coord->dir_x
		= coord->dir_x * cos(-coord->rot_speed)
		- coord->dir_y * sin(-coord->rot_speed);
	coord->dir_y
		= old_dir_x * sin(-coord->rot_speed)
		+ coord->dir_y * cos(-coord->rot_speed);
	coord->plane_x
		= coord->plane_x * cos(-coord->rot_speed)
		- coord->plane_y * sin(-coord->rot_speed);
	coord->plane_y
		= old_plane_x * sin(-coord->rot_speed)
		+ coord->plane_y * cos(-coord->rot_speed);
}

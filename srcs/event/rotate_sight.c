/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeongin <ljeongin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:17:22 by ljeongin          #+#    #+#             */
/*   Updated: 2022/11/02 09:17:23 by ljeongin         ###   ########.fr       */
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

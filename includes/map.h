/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:12:17 by ljeongin          #+#    #+#             */
/*   Updated: 2023/01/20 05:41:03 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stddef.h>
# include "macro.h"

typedef struct s_map		t_map;
typedef struct s_image		t_image;
typedef struct s_texture	t_texture;
typedef struct s_coord		t_coord;
typedef enum e_maparr		t_maparr;
typedef enum e_wall_dir		t_wall_dir;
typedef struct s_filepath	t_filepath;
typedef struct s_ray		t_ray;

struct s_map
{
	t_texture	*texture;
	t_coord		*coord;
};

struct s_image
{
	int		*addr;
	void	*img_ptr;
	int		bpp;
	int		sizel;
	int		endian;
};

struct s_texture
{
	t_image	*n;
	t_image	*e;
	t_image	*w;
	t_image	*s;
	int		floor;
	int		ceil;
};

struct s_coord
{
	t_maparr	**maparr;
	size_t		width;
	size_t		height;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
};

enum e_wall_dir
{
	NORTH_WALL = 0,
	EAST_WALL,
	WEST_WALL,
	SOUTH_WALL
};

struct s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	double		perp_walldist;
	double		line_height;
	int			start_point;
	int			end_point;
	int			hit;
	int			side;
	t_wall_dir	wall_dir;
	double		wall_x;
	double		step;
	double		texture_pos;
	int			texture_x;
	int			texture_y;
};

enum e_maparr
{
	WALL = 1 << 0,
	FIELD = 1 << 1,
	POS_N = 1 << 2,
	POS_E = 1 << 3,
	POS_W = 1 << 4,
	POS_S = 1 << 5,
	DOOR = 1 << 6,
	PLAYER = POS_N | POS_E | POS_W | POS_S,
};

struct s_filepath
{
	char	*n;
	char	*e;
	char	*w;
	char	*s;
};

#endif

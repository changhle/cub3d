#include <math.h>
#include "cub3d.h"
#include "map.h"

static void	transform_sprite(t_coord *coord, t_sprite *sprite)
{
	sprite->inv_det = 1.0 / (coord->plane_x * coord->dir_y
		- coord->dir_x * coord->plane_y);
	sprite->transform_x = sprite->inv_det * ()
}

void	sprite_cast(t_coord *coord, t_sprite *sprite, double z_buffer[])
{
	int		i;
	int		sprite_order[SPRITE_NUM];
	double	sprite_distance[SPRITE_NUM];

	i = 0;
	while (i < SPRITE_NUM)
	{
		sprite_order[i] = i;
		sprite_distance[i] = pow(coord->pos_x - sprite[i].x, 2)
			+ pow(coord->pos_y - sprite[i].y, 2);
		i++;
	}
	// sort_sprite();
	i = 0;
	while (i < SPRITE_NUM)
	{
		sprite->sprite_x = sprite[sprite_order[i]].x - coord->pos_x;
		sprite->sprite_y = sprite[sprite_order[i]].y - coord->pos_y;
		transform_sprite(coord, sprite);
	}
}
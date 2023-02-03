#include <math.h>
#include "cub3d.h"
#include "map.h"

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

static void	stripe_of_sprite(t_coord *coord, t_sprite *sprite)

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